#pragma once

typedef struct Window Window;
typedef struct WindowParam WindowParam;

void sceneInit(Window* window, WindowParam* params);

void sceneUpdate();
void sceneImguiUpdate();

void onSceneResize(unsigned int width, unsigned int height);