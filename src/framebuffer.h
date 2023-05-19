#pragma once
#include <stdbool.h>

#include "renderer.h"

enum FrameBufferFormat {

	FrameBufferFormat_None = 0,

	// Color Attachments
	FrameBufferFormat_RGBA8			= 1,
	FrameBufferFormat_RGBA16F		= 2,
	FrameBufferFormat_RGBA32F		= 3,

	// Depth Attachments
	FrameBufferFormat_DEPTH24_STENCIL_8 = 4
};

enum FrameBufferFiltering { FrameBufferFiltering_LINEAR, FrameBufferFiltering_NEAREST };

typedef enum FrameBufferFormat FrameBufferFormat;
typedef enum FrameBufferFiltering FrameBufferFiltering;

struct FrameBufferAttachmentSpec {
	FrameBufferFormat format;
	FrameBufferFiltering filtering;
	Vec4 clearColor;

	bool resizable;
};

typedef struct FrameBufferAttachmentSpec FrameBufferAttachmentSpec;

struct FrameBufferSpec {
	unsigned int width, height;

	FrameBufferAttachmentSpec* attachments;
	unsigned int colorattachment_count;
};

typedef struct FrameBufferSpec FrameBufferSpec;

struct FrameBuffer {
	unsigned int _framebuffer_id;

	FrameBufferSpec _framebuffer_spec;

	unsigned int* _color_attachmentIDs;
	unsigned int* _depth_attachment;
};

typedef struct FrameBuffer FrameBuffer;

FrameBuffer*	getFrameBuffer(FrameBufferSpec spec);

void			frameBufferBind(FrameBuffer* framebuffer);
void			frameBufferUnBind(FrameBuffer* framebuffer);
void			onFrameBufferResize(FrameBuffer* framebuffer, unsigned int width, unsigned int height);

void			destroyFrameBuffer(FrameBuffer* framebuffer);

unsigned int	getFrameBufferColorAttachmentCount(FrameBuffer* framebuffer);
unsigned int	getFrameBufferColorAttachment(FrameBuffer* framebuffer, unsigned int index);

void			bindColorAttachmentTexture(FrameBuffer* buffer, unsigned int color_attachment_index, unsigned int index);
