#include "framebuffer.h"
#include "macros.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <glad/gl.h>

// Private Functions:

void ConfigureTexture(unsigned int tex_id, unsigned int width, unsigned int height, GLenum format, GLenum internal_format, FrameBufferFiltering filtering)
{
	glTextureStorage2D(tex_id, 1, internal_format, width, height);
	glTextureSubImage2D(tex_id, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, NULL);
	
	glTextureParameteri(tex_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(tex_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTextureParameteri(tex_id, GL_TEXTURE_MAG_FILTER, filtering == FrameBufferFiltering_LINEAR ? GL_LINEAR : GL_NEAREST);
	glTextureParameteri(tex_id, GL_TEXTURE_MIN_FILTER, filtering == FrameBufferFiltering_LINEAR ? GL_LINEAR : GL_NEAREST);

}

FrameBuffer* getFrameBuffer(FrameBufferSpec spec)
{
	FrameBuffer* frameBuffer = (FrameBuffer*)malloc(sizeof(FrameBuffer));

	glCreateFramebuffers(1, &(frameBuffer->_framebuffer_id));
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer->_framebuffer_id);

	frameBuffer->_framebuffer_spec = spec;
	
	if (spec.colorattachment_count <= 3)
		frameBuffer->_color_attachmentIDs = (unsigned int*)malloc(spec.colorattachment_count * sizeof(unsigned int));
	else {
		fprintf(stderr, "colorattachment_count not initialised or too large!");
		TRIGGER_BREAKPOINT;
	}

	glCreateTextures(GL_TEXTURE_2D, spec.colorattachment_count, frameBuffer->_color_attachmentIDs);

	GLenum color_attach[3];

	for (int i = 0; i < frameBuffer->_framebuffer_spec.colorattachment_count; i++)
	{
		Vec4 clearColor;
		float color_data[4];

		switch (frameBuffer->_framebuffer_spec.attachments[i].format)
		{
		case FrameBufferFormat_RGBA8:
			ConfigureTexture(frameBuffer->_color_attachmentIDs[i],
				frameBuffer->_framebuffer_spec.width,
				frameBuffer->_framebuffer_spec.height,
				GL_RGBA8, GL_RGBA8,
				frameBuffer->_framebuffer_spec.attachments->filtering
				);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, frameBuffer->_color_attachmentIDs[i], 0);

			clearColor = frameBuffer->_framebuffer_spec.attachments[i].clearColor;
			color_data[0] = clearColor.x;
			color_data[1] = clearColor.y;
			color_data[2] = clearColor.z;
			color_data[3] = clearColor.w;

			glClearTexImage(frameBuffer->_color_attachmentIDs[i], 0, GL_RGB8, GL_FLOAT, color_data);
			break;
		case FrameBufferFormat_RGBA16F:
			ConfigureTexture(frameBuffer->_color_attachmentIDs[i],
				frameBuffer->_framebuffer_spec.width,
				frameBuffer->_framebuffer_spec.height,
				GL_RGBA16F, GL_RGBA16F,
				frameBuffer->_framebuffer_spec.attachments->filtering
			);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, frameBuffer->_color_attachmentIDs[i], 0);

			clearColor = frameBuffer->_framebuffer_spec.attachments[i].clearColor;
			color_data[0] = clearColor.x;
			color_data[1] = clearColor.y;
			color_data[2] = clearColor.z;
			color_data[3] = clearColor.w;

			glClearTexImage(frameBuffer->_color_attachmentIDs[i], 0, GL_RGB8, GL_FLOAT, color_data);
			break;
		case FrameBufferFormat_RGBA32F:
			ConfigureTexture(frameBuffer->_color_attachmentIDs[i],
				frameBuffer->_framebuffer_spec.width,
				frameBuffer->_framebuffer_spec.height,
				GL_RGBA32F, GL_RGBA32F,
				frameBuffer->_framebuffer_spec.attachments->filtering
			);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, frameBuffer->_color_attachmentIDs[i], 0);

			clearColor = frameBuffer->_framebuffer_spec.attachments[i].clearColor;
			color_data[0] = clearColor.x;
			color_data[1] = clearColor.y;
			color_data[2] = clearColor.z;
			color_data[3] = clearColor.w;

			glClearTexImage(frameBuffer->_color_attachmentIDs[i], 0, GL_RGB8, GL_FLOAT, color_data);
			break;
		}
		color_attach[i] = GL_COLOR_ATTACHMENT0 + i;

	}

	glDrawBuffers(frameBuffer->_framebuffer_spec.colorattachment_count, color_attach);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	return frameBuffer;
}

void frameBufferBind(FrameBuffer* framebuffer)
{
	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->_framebuffer_id);

	for (int i = 0; i < framebuffer->_framebuffer_spec.colorattachment_count; i++)
	{
		Vec4 clearColor = framebuffer->_framebuffer_spec.attachments[i].clearColor;
		float color_data[4] = { clearColor.x, clearColor.y, clearColor.z, clearColor.w };
		glClearTexImage(framebuffer->_color_attachmentIDs[i], 0, GL_RGB8, GL_FLOAT, color_data);
	}
}

void frameBufferUnBind(FrameBuffer* framebuffer)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void onFrameBufferResize(FrameBuffer* framebuffer, unsigned int width, unsigned int height)
{
	framebuffer->_framebuffer_spec.width = width;
	framebuffer->_framebuffer_spec.height = height;

	glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->_framebuffer_id);

	glDeleteTextures(framebuffer->_framebuffer_spec.colorattachment_count, framebuffer->_color_attachmentIDs);
	glCreateTextures(GL_TEXTURE_2D, framebuffer->_framebuffer_spec.colorattachment_count, framebuffer->_color_attachmentIDs);

	for (int i = 0; i < framebuffer->_framebuffer_spec.colorattachment_count; i++)
	{
		switch (framebuffer->_framebuffer_spec.attachments[i].format)
		{
		case FrameBufferFormat_RGBA8:
			ConfigureTexture(framebuffer->_color_attachmentIDs[i],
				framebuffer->_framebuffer_spec.width,
				framebuffer->_framebuffer_spec.height,
				GL_RGBA8, GL_RGBA8,
				framebuffer->_framebuffer_spec.attachments->filtering
			);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, framebuffer->_color_attachmentIDs[i], 0);
			break;
		case FrameBufferFormat_RGBA16F:
			ConfigureTexture(framebuffer->_color_attachmentIDs[i],
				framebuffer->_framebuffer_spec.width,
				framebuffer->_framebuffer_spec.height,
				GL_RGBA16F, GL_RGBA16F,
				framebuffer->_framebuffer_spec.attachments->filtering
			);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, framebuffer->_color_attachmentIDs[i], 0);
			break;
		case FrameBufferFormat_RGBA32F:
			ConfigureTexture(framebuffer->_color_attachmentIDs[i],
				framebuffer->_framebuffer_spec.width,
				framebuffer->_framebuffer_spec.height,
				GL_RGBA32F, GL_RGBA32F,
				framebuffer->_framebuffer_spec.attachments->filtering
			);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, framebuffer->_color_attachmentIDs[i], 0);
			break;
		}
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void destroyFrameBuffer(FrameBuffer* framebuffer)
{
	free((void*)framebuffer);
}

unsigned int getFrameBufferColorAttachmentCount(FrameBuffer* framebuffer)
{
	return framebuffer->_framebuffer_spec.colorattachment_count;
}

unsigned int getFrameBufferColorAttachment(FrameBuffer* framebuffer, unsigned int index)
{
	return framebuffer->_color_attachmentIDs[index];
}

void bindColorAttachmentTexture(FrameBuffer* buffer, unsigned int color_attachment_index, unsigned int index)
{
	glBindTextureUnit(index, buffer->_color_attachmentIDs[color_attachment_index]);
}
