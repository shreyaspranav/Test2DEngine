#pragma once

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };

typedef struct Vec2 Vec2;
typedef struct Vec3 Vec3;
typedef struct Vec4 Vec4;

void rendererInit(unsigned int width, unsigned int height);

void rendererBegin();
void renderFrame();

void rendererTerminate();

void drawClearQuad(Vec3 position, float rotation, Vec2 scale, Vec4 color);
void addPointLight(Vec2 position, Vec4 color, float radius, float falloffA, float fallofB);

void clearScreen(float r, float g, float b, float a);
void onRendererFrameBufferResize(unsigned int width, unsigned int height);
void setRendererCameraPosition(Vec2* pos);
void setRendererCameraScale(float* scale);