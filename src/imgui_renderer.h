#pragma once

#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define CIMGUI_USE_GLFW
#define CIMGUI_USE_OPENGL3

#include "cimgui.h"
#include "cimgui_impl.h"

#include "window.h"

void	imgui_init(GLFWwindow* window);
void	imgui_terminate();

void	imgui_start_frame();
void	imgui_end_frame();