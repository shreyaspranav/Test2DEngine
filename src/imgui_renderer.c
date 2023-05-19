#include "imgui_renderer.h"

struct ImGuiContext* ctx;
struct ImGuiIO* io;

void imgui_init(GLFWwindow* window)
{
	ctx = igCreateContext(NULL);

    io = igGetIO();

    glfwInit();

    const char* glsl_version = "#version 460 core";
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    igStyleColorsDark(NULL);
}
void imgui_terminate()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    igDestroyContext(ctx);
}
	 
void imgui_start_frame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    igNewFrame();
}

void imgui_end_frame()
{
    igRender();
    ImGui_ImplOpenGL3_RenderDrawData(igGetDrawData());
}