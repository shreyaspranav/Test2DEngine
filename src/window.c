#include <stdio.h>
#include <stdlib.h>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

#include "window.h"
#include "macros.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Window* win = (Window*)glfwGetWindowUserPointer(window);
    win->_callbacks._key_callback(key, action);
}

void windowResize(GLFWwindow* window, int width, int height)
{
    Window* win = (Window*)glfwGetWindowUserPointer(window);

    win->_param->width = width;
    win->_param->height = height;

    win->_callbacks._window_resize_callback(width, height);
}

Window* createWindow(WindowParam* params)
{
    Window* _window = (Window*)malloc(sizeof(Window));

    _window->_param = params;

    if (!glfwInit())
    {
        fprintf(stderr, "GLFW Failed to Initialise!");
        TRIGGER_BREAKPOINT;
    }

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    _window->_window = glfwCreateWindow(params->width, params->height, params->title, NULL, NULL);
    glfwShowWindow(_window->_window);

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(_window->_window, (mode->width - params->width) / 2, (mode->height - params->height) / 2);
    
    glfwSwapInterval(0);

    glfwSetWindowUserPointer(_window->_window, _window);
    glfwSetInputMode(_window->_window, GLFW_STICKY_KEYS, GLFW_TRUE);

    return _window;
}
void updateWindow(Window* window)
{
    glfwSwapBuffers(window->_window);
    glfwPollEvents();
}
void destroyWindow(Window* window)
{
    glfwDestroyWindow(window->_window);
    glfwTerminate();

    free((void*)window);
}

void setVsync(Window* window, bool vsync)
{
    glfwSwapInterval(vsync);
}

void createContext(Window* window)
{
    glfwMakeContextCurrent(window->_window);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0)
    {
        fprintf(stderr, "Glad Failed to load!");
        TRIGGER_BREAKPOINT;
    }

    printf("Loaded OpenGL %d.%d", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
}

bool windowShouldClose(Window* window)
{
    return glfwWindowShouldClose(window->_window);
}

void getMouseCoords(Window* window, double* x, double* y)
{
    glfwGetCursorPos(window->_window, x, y);
}

Vec2 getRendererMouseCoords(Window* window, float* x, float* y, Vec2 camera_pos, float cam_scale)
{
    double _x, _y;
    int width, height;

    getMouseCoords(window, &_x, &_y);
    glfwGetWindowSize(window->_window, &width, &height);

    _x /= width;
    _y /= height;

    _x *= 2;
    _y *= 2;

    _x -= 1.0;
    _y = 1.0 - _y;

    _x *= ((double)width / height);

    _x += camera_pos.x * cam_scale;
    _y += camera_pos.y * cam_scale;

    Vec2 to_return = { _x, _y };
    return to_return;
}

bool isKeyPressed(Window* window, int keycode)
{
    return glfwGetKey(window->_window, keycode) == GLFW_PRESS;
}

void addKeyCallback(Window* window, KeyCallbackFn fn)
{
    window->_callbacks._key_callback = fn;
    glfwSetKeyCallback(window->_window, key_callback);
}

void addWindowResizeCallback(Window* window, WindowResizeCallbackFn fn)
{
    window->_callbacks._window_resize_callback = fn;
    glfwSetWindowSizeCallback(window->_window, windowResize);
}