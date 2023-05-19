#include "scene.h"

#include <stdlib.h>
#include "imgui_renderer.h"
#include "window.h"
#include "renderer.h"

struct _SceneData 
{
	Window* window;
	WindowParam* params;

	float quad_pos[2];
	float light_falloff[2];

	float random_pos_vals[20];
	float rand_val[20];

	float light_radius;
	Vec2 light_positions[1000];
	unsigned int light_count;
};

float random() { return ((float)rand() / (float)(RAND_MAX)); }

struct _SceneData sceneData;

void KeyCallback(int key, int action)
{
	if (action == GLFW_PRESS && key == GLFW_KEY_SPACE)
	{
		printf("Pressed!. Light Count: %d\n", sceneData.light_count);
		if (sceneData.light_count < 1000)
			sceneData.light_count++;
	}
}

void sceneInit(Window* window, WindowParam* params)
{
	sceneData.window = window;
	sceneData.params = params;

	rendererInit(params->width, params->height);
	imgui_init(window->_window);

	sceneData.light_falloff[0] = 1.0f;
	sceneData.light_falloff[1] = 1.0f;

	sceneData.light_radius = 1.0f;

	addKeyCallback(sceneData.window, KeyCallback);

	for (int i = 0; i < 20; i++)
		sceneData.random_pos_vals[i] = (random() * 2.0f) - 1.0f;
	for (int i = 0; i < 20; i++)
		sceneData.rand_val[i] = random();

	sceneData.light_count = 1;
}

void sceneUpdate()
{
	rendererBegin();

	float x, y;

	Vec2 mouse = getRendererMouseCoords(sceneData.window, &x, &y, (Vec2) { 0.0f, 0.0f }, 1.0f);
	sceneData.light_positions[sceneData.light_count - 1] = mouse;

	for(int i = 4; i < 9; i++)
		drawClearQuad((Vec3) { sceneData.random_pos_vals[(2 * i) + 1], sceneData.random_pos_vals[2 * i], 0.0f },
			0.0f, (Vec2) { 0.6f, 0.6f }, 
			(Vec4) { 1.0f, 1.0f, 1.0f, 1.0f });

	for(int i = 0; i < sceneData.light_count; i++)
		addPointLight((Vec2) { sceneData.light_positions[i].x, sceneData.light_positions[i].y}, (Vec4) { sceneData.rand_val[i], 1.0f, sceneData.rand_val[2 * i], 1.0f }, sceneData.light_radius, sceneData.light_falloff[0], sceneData.light_falloff[1]);

	renderFrame();
}

void sceneImguiUpdate()
{
	imgui_start_frame();

	bool boo = true;

	igBegin("Square Test", &boo, NULL);
	igDragFloat2("Light Falloff", sceneData.light_falloff, 0.01f, 0.0f, 20.0f, "%.2f", NULL);
	igDragFloat("Light Radius", &sceneData.light_radius, 0.01f, 0.0f, 20.0f, "%.2f", NULL);

	igEnd();

	//igShowDemoWindow(boo);

	imgui_end_frame();
}

void onSceneResize(unsigned int width, unsigned int height)
{
	onRendererFrameBufferResize(width, height);
}