cmake_minimum_required(VERSION 3.18)

add_subdirectory(deps/glfw)
add_subdirectory(deps/cglm)
add_subdirectory(deps/cimgui)

target_link_libraries(cimgui glfw)

project(Test2DEngine LANGUAGES C)

#set_property(TARGET Test2DEngine PROPERTY C_STANDARD 11)

add_executable(Test2DEngine "src/main.c"            "src/window.c"          "src/shader.c"
                            "src/renderer.c"        "src/buffer.c"          "src/framebuffer.c" 
                            "src/imgui_renderer.h"  "src/imgui_renderer.c"  "src/scene.c")

target_include_directories(Test2DEngine PRIVATE "deps/glfw/include" "deps/glad/include"
                                                "deps/glm/glm" "deps/cimgui" "deps/cimgui/imgui")

target_compile_definitions(Test2DEngine PRIVATE IMGUI_IMPL_API=\ )

target_link_libraries(Test2DEngine glfw cglm cimgui)