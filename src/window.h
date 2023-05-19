#pragma once
#include <stdbool.h>

#include <GLFW/glfw3.h>

#include "renderer.h"

typedef void (*WindowResizeCallbackFn)(unsigned int width, unsigned int height);
typedef void (*KeyCallbackFn)(int key, int action);

struct WindowParam {
    unsigned int width, height;
    char* title;
};

struct WindowCallbacks {
    WindowResizeCallbackFn _window_resize_callback;
    KeyCallbackFn _key_callback;
};

typedef struct WindowParam WindowParam;
typedef struct WindowCallbacks WindowCallbacks;

struct Window {
    WindowParam* _param;
    GLFWwindow* _window;

    WindowCallbacks _callbacks;
};

typedef struct Window Window;

Window* createWindow(WindowParam* params);

void    updateWindow(Window* window);
void    destroyWindow(Window* window);

void    setVsync(Window* window, bool vsync);
void    createContext(Window* window);

bool    windowShouldClose(Window* window);
void    getMouseCoords(Window* window, double* x, double* y);
Vec2    getRendererMouseCoords(Window* window, float* x, float* y, Vec2 camera_pos, float cam_scale);

void    addKeyCallback(Window* window, KeyCallbackFn fn);
void    addWindowResizeCallback(Window* window, WindowResizeCallbackFn fn); 