#pragma once

const char* vertex_src = "#version 460 core\n"
"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec4 aCol;\n"

"out vec4 col;\n"
"out float zCoord;\n"

"uniform mat4 u_ViewProjection;\n"

"void main() {\n"
	"gl_Position = u_ViewProjection * vec4(aPos, 1.0);\n"
	"col = aCol;\n"
	"zCoord = aPos.z;\n"
"}";

const char* fragment_src = "#version 460 core\n"
"in vec4 col;\n"
"in float zCoord;\n"

"layout(location = 0) out vec4 fragColor;\n"
"layout(location = 1) out vec4 depthColor;\n"

"void main() {\n"
	"float depth_color = (zCoord + 1.0) / 2.0;\n"
	
	"fragColor = col;\n"
	"depthColor = vec4(depth_color, depth_color, depth_color, 1.0);\n"
"}";

const char* display_vertex_src = "#version 460 core\n"
"layout(location = 0) in vec2 aPos;\n"
"layout(location = 1) in vec2 aTexCoord;\n"

"out vec2 TexCoord;\n"

"void main() {\n"
	"gl_Position = vec4(aPos, 1.0, 1.0);\n"
	"TexCoord = aTexCoord;\n"
"}";

const char* display_fragment_src = "#version 460 core\n"
"in vec2 TexCoord;\n"

"out vec4 fragColor;\n"

"uniform sampler2D u_DisplayTexture;\n"
"uniform sampler2D u_DisplayDepthTexture;\n"
"uniform sampler2D u_LightTexture;\n"

"void main() {\n"
	"// Assuming that near point and far point is 1.0f and -1.0f\n"
	"vec4 de_color = texture(u_DisplayDepthTexture, TexCoord);\n"
	"float depth_color = (de_color.x * 2.0) - 1.0;\n"
	"fragColor = texture(u_DisplayTexture, TexCoord) * texture(u_LightTexture, TexCoord) * (1.0 - depth_color);\n"
"}";

const char* light_vertex_src = "#version 460 core\n"
"layout(location = 0) in vec2 aPos;\n"
"layout(location = 1) in vec4 aColor;\n"
"layout(location = 2) in vec2 aWorldCoord;\n"
"layout(location = 3) in float aLightFactorA;\n"
"layout(location = 4) in float aLightFactorB;\n"

"out vec4 Color;\n"
"out vec2 WorldCoord;\n"
"out float LightFactorA;\n"
"out float LightFactorB;\n"

"uniform mat4 u_ViewProjection;\n"

"void main() {\n"
	"gl_Position = u_ViewProjection * vec4(aPos, 1.0, 1.0);\n"

	"Color = aColor;\n"
	"WorldCoord = aWorldCoord;\n"
	"LightFactorA = aLightFactorA;\n"
	"LightFactorB = aLightFactorB;\n"
"}";

const char* light_fragment_src = "#version 460 core\n"

"in vec4 Color;\n"
"in vec2 WorldCoord;\n"
"in float LightFactorA;\n"
"in float LightFactorB;\n"

"layout(location = 0) out vec4 fragColor;\n"

"void main() {\n"
	"highp float d = length(WorldCoord);\n"
	"highp float light_intensity = 1.0 / (1.0 + (d * LightFactorA) + (d * d * LightFactorB));\n"
	"//float light_intensity = 1.0 - (d * LightFactorA);\n"

	"fragColor = highp vec4(light_intensity, light_intensity, light_intensity, 1.0) * Color;\n"
"}";
