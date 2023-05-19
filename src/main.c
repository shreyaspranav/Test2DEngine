#include <stdio.h>

#include "scene.h"
#include "window.h"

WindowParam window_params;

void onWindowResize(unsigned int width, unsigned int height)
{
    onSceneResize(width, height);
}

int main(int argc, char** argv)
{
    Window* window;

    window_params.width = 1600;
    window_params.height = 900;
    window_params.title = "Test 2D Engine";

    window = createWindow(&window_params);
    createContext(window);
    addWindowResizeCallback(window, onWindowResize);

    sceneInit(window, &window_params);

    while(!windowShouldClose(window))
    {
        sceneUpdate();
        sceneImguiUpdate();

        updateWindow(window);
    }

    rendererTerminate();
    imgui_terminate();
    destroyWindow(window);
}