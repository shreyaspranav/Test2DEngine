#include "renderer.h"
#include <glad/gl.h>

#include "buffer.h"
#include "shader.h"
#include "framebuffer.h"
#include "shader_source.h"
#include <stddef.h>

#include <cglm/struct.h>

unsigned int max_vertex_count = 400000;

struct Camera {
	mat4 projection_mat;
	mat4 view_mat;
	mat4 view_projection_mat;
};

struct _RendererStorage {
	Buffer* main_vertex_buffer;
	Buffer* main_element_buffer;

	Buffer* display_vertex_buffer;
	Buffer* display_element_buffer;

	Buffer* light_vertex_buffer;
	Buffer* light_element_buffer;

	BufferLayout main_layout;
	BufferLayout display_layout;
	BufferLayout light_layout;

	VertexArray* main_vertex_array;
	VertexArray* display_vertex_array;
	VertexArray* light_vertex_array;

	Shader main_shader;
	Shader display_shader;
	Shader light_shader;

	FrameBuffer* main_frame_buffer;
	FrameBuffer* light_frame_buffer;

	vec3 camera_scale;
	vec3 camera_pos;
	struct Camera camera;

	unsigned int framebuffer_width;
	unsigned int framebuffer_height;

	float* vertex_data;
	unsigned int* index_data;

	float* light_vertex_data;
	unsigned int* light_index_data;

	unsigned int main_vertex_index, main_element_index;
	unsigned int light_vertex_index, light_element_index;

	float ambient_light;
};

enum BlendType { BlendType_EQUAL_CONTIBUTION = 0, BlendType_ADDITIVE = 1 };
typedef enum BlendType BlendType;

struct _RendererStorage renderer_storage;

float screen_quad[16] = {
	 1.0f,  1.0f, 1.0f, 1.0f,
	-1.0f,  1.0f, 0.0f, 1.0f,
	-1.0f, -1.0f, 0.0f, 0.0f,
	 1.0f, -1.0f, 1.0f, 0.0f,
};

Vec4 GetColor(float r, float g, float b, float a) { return (Vec4) { r, g, b, a }; }

unsigned int ind_data[6] = { 0, 1, 2, 0, 2, 3 };

const unsigned int main_stride_count = 7;
const unsigned int light_stride_count = 10;


FrameBufferSpec main_fb_spec;
FrameBufferAttachmentSpec main_fb_attachments[2];

FrameBufferSpec light_fb_spec;
FrameBufferAttachmentSpec light_fb_attachments[1];

// OpenGL Funcs ----------------------------------------------------
// -----------------------------------------------------------------

void DrawIndexed(unsigned int count, unsigned int offset) { 
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void*)0);
}

void SetViewport(unsigned int width, unsigned int height) {
	glViewport(0, 0, width, height);
}

void EnableBlending() {
	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
}

void SetBlending(BlendType type) {

	switch (type)
	{
	case BlendType_EQUAL_CONTIBUTION:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BlendType_ADDITIVE:
		glBlendFunc(GL_ONE, GL_ONE);
		break;
	default:
		break;
	}
}

void ClearBuffers() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void clearScreen(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void SetupCamera(unsigned int width, unsigned int height) {
	glm_ortho(-(float)width / height, (float)width / height, -1.0f, 1.0f, -1.0f, 1.0f, renderer_storage.camera.projection_mat);

	renderer_storage.camera_pos[0] = 0.0f;
	renderer_storage.camera_pos[1] = 0.0f;
	renderer_storage.camera_pos[2] = 0.0f;

	renderer_storage.camera_scale[0] = 1.0f;
	renderer_storage.camera_scale[1] = 1.0f;
	renderer_storage.camera_scale[2] = 1.0f;

	glm_mat4_identity(renderer_storage.camera.view_mat);

	glm_translate(renderer_storage.camera.view_mat, renderer_storage.camera_pos);
	glm_scale(renderer_storage.camera.view_mat, renderer_storage.camera_scale);

	glm_inv_tr(renderer_storage.camera.view_mat);

	glm_mat4_mul(renderer_storage.camera.projection_mat,
		renderer_storage.camera.view_mat,
		renderer_storage.camera.view_projection_mat);
}

// Renderer Functions:
void rendererInit(unsigned int width, unsigned int height)
{
	SetupCamera(width, height);

	//Normal Buffer
	renderer_storage.main_layout = createBufferLayout(2);
	
	addBufferElement(&renderer_storage.main_layout, 0, 3, 0, false);
	addBufferElement(&renderer_storage.main_layout, 1, 4, 3, false);
	
	renderer_storage.main_vertex_array = createVertexArray(&renderer_storage.main_layout);
	
	renderer_storage.main_vertex_buffer = createBuffer(BufferType_FLOAT_BUFFER, max_vertex_count, NULL);
	renderer_storage.main_element_buffer = createBuffer(BufferType_ELEMENT_BUFFER, (unsigned int)(max_vertex_count * 1.5), NULL);
	
	finalize(renderer_storage.main_vertex_array, renderer_storage.main_vertex_buffer, renderer_storage.main_element_buffer);

	renderer_storage.main_shader = loadAndCompileShaders(vertex_src, fragment_src);

	//Light Buffer
	renderer_storage.light_layout = createBufferLayout(5);

	addBufferElement(&renderer_storage.light_layout, 0, 2, 0, false);
	addBufferElement(&renderer_storage.light_layout, 1, 4, 2, false);
	addBufferElement(&renderer_storage.light_layout, 2, 2, 6, false);
	addBufferElement(&renderer_storage.light_layout, 3, 1, 8, false);
	addBufferElement(&renderer_storage.light_layout, 4, 1, 9, false);

	renderer_storage.light_vertex_array = createVertexArray(&renderer_storage.light_layout);

	renderer_storage.light_vertex_buffer = createBuffer(BufferType_FLOAT_BUFFER, max_vertex_count, NULL);
	renderer_storage.light_element_buffer = createBuffer(BufferType_ELEMENT_BUFFER, (unsigned int)(max_vertex_count * 1.5), NULL);

	finalize(renderer_storage.light_vertex_array, renderer_storage.light_vertex_buffer, renderer_storage.light_element_buffer);

	renderer_storage.light_shader = loadAndCompileShaders(light_vertex_src, light_fragment_src);

	// Screen Buffer
	renderer_storage.display_layout = createBufferLayout(2);

	addBufferElement(&renderer_storage.display_layout, 0, 2, 0, false);
	addBufferElement(&renderer_storage.display_layout, 1, 2, 2, false);

	renderer_storage.display_vertex_array = createVertexArray(&renderer_storage.display_layout);

	renderer_storage.display_vertex_buffer = createBuffer(BufferType_FLOAT_BUFFER, 16, screen_quad);
	renderer_storage.display_element_buffer = createBuffer(BufferType_ELEMENT_BUFFER, 6, ind_data);

	finalize(renderer_storage.display_vertex_array, renderer_storage.display_vertex_buffer, renderer_storage.display_element_buffer);

	renderer_storage.display_shader = loadAndCompileShaders(display_vertex_src, display_fragment_src);

	EnableBlending();

	renderer_storage.framebuffer_width = width;
	renderer_storage.framebuffer_height = height;

	renderer_storage.vertex_data = (float*)malloc(max_vertex_count * sizeof(float));
	renderer_storage.index_data = (float*)malloc(max_vertex_count * sizeof(unsigned int));

	renderer_storage.light_vertex_data = (float*)malloc(max_vertex_count * sizeof(float));
	renderer_storage.light_index_data = (float*)malloc(max_vertex_count * sizeof(unsigned int));

	renderer_storage.main_vertex_index = 0;
	renderer_storage.light_vertex_index = 0;

	main_fb_attachments[0] = (FrameBufferAttachmentSpec){ FrameBufferFormat_RGBA8, FrameBufferFiltering_LINEAR, GetColor(0.0f, 0.0f, 0.0f, 1.0f), true };
	main_fb_attachments[1] = (FrameBufferAttachmentSpec){ FrameBufferFormat_RGBA8, FrameBufferFiltering_LINEAR, GetColor(0.4f, 0.4f, 0.4f, 1.0f), true };
	
	light_fb_attachments[0] = (FrameBufferAttachmentSpec){ FrameBufferFormat_RGBA8, FrameBufferFiltering_LINEAR, GetColor(0.0f, 0.0f, 0.0f, 1.0f), true };

	main_fb_spec.width = width;
	main_fb_spec.height = height;
	main_fb_spec.attachments = main_fb_attachments;
	main_fb_spec.colorattachment_count = 2;

	light_fb_spec.width = width;
	light_fb_spec.height = height;
	light_fb_spec.attachments = light_fb_attachments;
	light_fb_spec.colorattachment_count = 1;

	renderer_storage.main_frame_buffer = getFrameBuffer(main_fb_spec);
	renderer_storage.light_frame_buffer = getFrameBuffer(light_fb_spec);

	renderer_storage.ambient_light = 0.2f;
}

void rendererBegin() 
{
	renderer_storage.main_vertex_index = 0;
	renderer_storage.main_element_index = 0;

	renderer_storage.light_vertex_index = 0;
	renderer_storage.light_element_index = 0;
}

void renderFrame()
{
	// Render Scene:
	bindVertexArray(renderer_storage.main_vertex_array);
	useShader(&renderer_storage.main_shader);

	setUniformMatrix4f(renderer_storage.main_shader, "u_ViewProjection", renderer_storage.camera.view_projection_mat[0]);

	setBufferData(renderer_storage.main_vertex_buffer, renderer_storage.vertex_data, 0, renderer_storage.main_vertex_index * main_stride_count);
	setBufferData(renderer_storage.main_element_buffer, renderer_storage.index_data, 0, renderer_storage.main_element_index);

	frameBufferBind(renderer_storage.main_frame_buffer);

	ClearBuffers();
	//clearScreen(0.0f, 0.0f, 0.0f, 1.0f);
	SetBlending(BlendType_EQUAL_CONTIBUTION);

	DrawIndexed(renderer_storage.main_element_index, 0);
	frameBufferUnBind(renderer_storage.main_frame_buffer);

	// Render Lights:
	bindVertexArray(renderer_storage.light_vertex_array);
	useShader(&renderer_storage.light_shader);

	setUniformMatrix4f(renderer_storage.light_shader, "u_ViewProjection", renderer_storage.camera.view_projection_mat[0]);

	setBufferData(renderer_storage.light_vertex_buffer, renderer_storage.light_vertex_data, 0, renderer_storage.light_vertex_index * light_stride_count);
	setBufferData(renderer_storage.light_element_buffer, renderer_storage.light_index_data, 0, renderer_storage.light_element_index);

	frameBufferBind(renderer_storage.light_frame_buffer);

	ClearBuffers();
	//clearScreen(0.0f, 0.0f, 0.0f, 1.0f);
	SetBlending(BlendType_ADDITIVE);

	DrawIndexed(renderer_storage.main_element_index, 0);
	frameBufferUnBind(renderer_storage.light_frame_buffer);
	
	// Render Screen Quad:
	bindVertexArray(renderer_storage.display_vertex_array);
	useShader(&renderer_storage.display_shader);

	bindColorAttachmentTexture(renderer_storage.main_frame_buffer, 0, 0);
	bindColorAttachmentTexture(renderer_storage.main_frame_buffer, 1, 1);
	bindColorAttachmentTexture(renderer_storage.light_frame_buffer, 0, 2);

	setUniformInt(renderer_storage.display_shader, "u_DisplayTexture", 0);
	setUniformInt(renderer_storage.display_shader, "u_DisplayDepthTexture", 1);
	setUniformInt(renderer_storage.display_shader, "u_LightTexture", 2);

	ClearBuffers();

	SetBlending(BlendType_EQUAL_CONTIBUTION);
	DrawIndexed(6, 0);
}

void drawClearQuad(Vec3 position, float rotation, Vec2 scale, Vec4 color)
{
	// Index Buffer:
	for (int i = 0; i < 6; i++)
		renderer_storage.index_data[renderer_storage.main_element_index + i] = renderer_storage.main_vertex_index + ind_data[i];

	renderer_storage.main_element_index += 6;

	// X and Y Coordinates:

	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 0] = position.x + (0.5f * scale.x);
	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 1] = position.y + (0.5f * scale.y);

	renderer_storage.main_vertex_index++;

	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 0] = position.x - (0.5f * scale.x);
	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 1] = position.y + (0.5f * scale.y);

	renderer_storage.main_vertex_index++;

	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 0] = position.x - (0.5f * scale.x);
	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 1] = position.y - (0.5f * scale.y);

	renderer_storage.main_vertex_index++;

	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 0] = position.x + (0.5f * scale.x);
	renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 1] = position.y - (0.5f * scale.y);

	renderer_storage.main_vertex_index -= 3;

	for (int i = 0; i < 4; i++)
	{
		// Z Coordinate:
		renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 2] = position.z;

		// Color: 
		renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 3] = color.x;
		renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 4] = color.y;
		renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 5] = color.z;
		renderer_storage.vertex_data[(renderer_storage.main_vertex_index * main_stride_count) + 6] = color.w;

		renderer_storage.main_vertex_index++;
	}
}

void addPointLight(Vec2 position, Vec4 color, float radius, float falloffA, float falloffB)
{
	// Index Buffer:
	for (int i = 0; i < 6; i++)
		renderer_storage.light_index_data[renderer_storage.light_element_index + i] = renderer_storage.light_vertex_index + ind_data[i];

	renderer_storage.light_element_index += 6;

	// X and Y Coordinates:
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 0] = position.x + (0.5f * radius);
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 1] = position.y + (0.5f * radius);

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 0] = position.x - (0.5f * radius);
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 1] = position.y + (0.5f * radius);

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 0] = position.x - (0.5f * radius);
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 1] = position.y - (0.5f * radius);

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 0] = position.x + (0.5f * radius);
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 1] = position.y - (0.5f * radius);

	renderer_storage.light_vertex_index -= 3;

	// World Coords:
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 6] =  10.0f;
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 7] =  10.0f;

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 6] = -10.0f;
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 7] =  10.0f;

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 6] = -10.0f;
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 7] = -10.0f;

	renderer_storage.light_vertex_index++;

	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 6] =  10.0f;
	renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 7] = -10.0f;

	renderer_storage.light_vertex_index -= 3;

	for (int i = 0; i < 4; i++)
	{
		// Color: 
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 2] = color.x;
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 3] = color.y;
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 4] = color.z;
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 5] = color.w;

		// FalloffA and FalloffB
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 8] = falloffA;
		renderer_storage.light_vertex_data[(renderer_storage.light_vertex_index * light_stride_count) + 9] = falloffB;

		renderer_storage.light_vertex_index++;
	}
}

void onRendererFrameBufferResize(unsigned int width, unsigned int height)
{
	glm_ortho(-(float)width / height, (float)width / height, -1.0f, 1.0f, -1.0f, 1.0f, renderer_storage.camera.projection_mat);

	glm_mat4_mul(renderer_storage.camera.projection_mat,
		renderer_storage.camera.view_mat,
		renderer_storage.camera.view_projection_mat);

	onFrameBufferResize(renderer_storage.main_frame_buffer, width, height);
	onFrameBufferResize(renderer_storage.light_frame_buffer, width, height);

	SetViewport(width, height);

	renderer_storage.framebuffer_width = width;
	renderer_storage.framebuffer_height = height;
 }

void setRendererCameraPosition(Vec2* pos)
{
	renderer_storage.camera_pos[0] = pos->x;
	renderer_storage.camera_pos[1] = pos->y;
}

void setRendererCameraScale(float* scale)
{
	renderer_storage.camera_scale[0] = *scale;
	renderer_storage.camera_scale[1] = *scale;
}

void rendererTerminate()
{
	destroyBuffer(renderer_storage.main_vertex_buffer);
	destroyBuffer(renderer_storage.main_element_buffer);

	destroyVertexArray(renderer_storage.main_vertex_array);

	destroyFrameBuffer(renderer_storage.main_frame_buffer);

	free((void*)renderer_storage.vertex_data);
	free((void*)renderer_storage.index_data);

	destroyBuffer(renderer_storage.light_vertex_buffer);
	destroyBuffer(renderer_storage.light_element_buffer);

	destroyVertexArray(renderer_storage.light_vertex_array);

	destroyFrameBuffer(renderer_storage.light_frame_buffer);

	free((void*)renderer_storage.light_vertex_data);
	free((void*)renderer_storage.light_index_data);
}