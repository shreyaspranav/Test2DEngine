
#include "buffer.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>

#include <glad/gl.h>

// Buffer API--------------------------------------------------------------------
// ------------------------------------------------------------------------------
Buffer* createBuffer(BufferType type, unsigned int max_count, void* data)
{
	Buffer* buffer = (Buffer*)malloc(sizeof(Buffer));
	glCreateBuffers(1, &buffer->_bufferID);

	if (type == BufferType_FLOAT_BUFFER) {
		buffer->_size_per_value = sizeof(float);
		glBindBuffer(GL_ARRAY_BUFFER, buffer->_bufferID);
		glBufferData(GL_ARRAY_BUFFER, max_count * buffer->_size_per_value, data, GL_DYNAMIC_DRAW);
	}

	else if (type == BufferType_ELEMENT_BUFFER) {
		buffer->_size_per_value = sizeof(unsigned int);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->_bufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, max_count * buffer->_size_per_value, data, GL_DYNAMIC_DRAW);
	}

	buffer->_count = max_count;
	buffer->_bufferType = type;

	return buffer;
}
void setBufferData(Buffer* buffer, void* data, unsigned int offset_count, unsigned int count)
{
	unsigned int available_count = buffer->_count - offset_count;

	if (available_count < count)
	{
		fprintf(stderr, "Buffer overflow!");
		TRIGGER_BREAKPOINT;
	}

	if (buffer->_bufferType == BufferType_FLOAT_BUFFER) {
		glBindBuffer(GL_ARRAY_BUFFER, buffer->_bufferID);
		glBufferSubData(GL_ARRAY_BUFFER, offset_count * sizeof(unsigned int), count * sizeof(unsigned int), data);
	}

	else if (buffer->_bufferType == BufferType_ELEMENT_BUFFER) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->_bufferID);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset_count * sizeof(unsigned int), count * sizeof(unsigned int), data);
	}
}
void destroyBuffer(Buffer* buffer)
{
	glDeleteBuffers(1, &buffer->_bufferID);
	free((void*)buffer);
}

BufferType getBufferType(Buffer* buffer)
{
	return buffer->_bufferType;
}

unsigned int getBufferCount(Buffer* buffer)
{
	return buffer->_count;
}

// BufferLayout API -------------------------------------------------------------
// ------------------------------------------------------------------------------
BufferLayout createBufferLayout(unsigned short shader_loc_count)
{
	BufferLayout layout;
	layout._count = shader_loc_count;
	layout._index = 0;

	layout._shader_locations	= (short*)malloc(shader_loc_count * sizeof(short));
	layout._count_per_vertices	= (short*)malloc(shader_loc_count * sizeof(short));
	layout._offset_counts		= (short*)malloc(shader_loc_count * sizeof(short));
	layout._normalised			= (short*)malloc(shader_loc_count * sizeof(short));

	return layout;
}

void addBufferElement(BufferLayout* layout, unsigned short shader_location, unsigned short count_per_vertex, unsigned short offset_count, bool normalised)
{
	layout->_shader_locations[layout->_index]		= shader_location;
	layout->_count_per_vertices[layout->_index]		= count_per_vertex;
	layout->_offset_counts[layout->_index]			= offset_count;
	layout->_normalised[layout->_index]				= normalised;

	layout->_index++;
}

short getBufferElementCount(BufferLayout* layout)
{
	return layout->_count;
}


// VertexArray API --------------------------------------------------------------
// ------------------------------------------------------------------------------
VertexArray* createVertexArray(BufferLayout* buffer_layout)
{
	VertexArray* vertex_array = (VertexArray*)malloc(sizeof(VertexArray));
	vertex_array->_layout = *(buffer_layout);

	glCreateVertexArrays(1, &vertex_array->_vertex_array_id);

	return vertex_array;
}

void finalize(VertexArray* vertex_array, Buffer* vertex_buffer, Buffer* element_buffer)
{
	glBindVertexArray(vertex_array->_vertex_array_id);

	vertex_array->_vertex_buffer = vertex_buffer;
	vertex_array->_element_buffer = element_buffer;
	unsigned short stride_count = 0;

	for (int i = 0; i < vertex_array->_layout._count; i++)
		stride_count += vertex_array->_layout._count_per_vertices[i];

	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer->_bufferID);

	for (int i = 0; i < vertex_array->_layout._count; i++) {
		glVertexAttribPointer(
			vertex_array->_layout._shader_locations[i],
			vertex_array->_layout._count_per_vertices[i],
			GL_FLOAT,
			vertex_array->_layout._normalised[i] ? GL_TRUE : GL_FALSE,
			stride_count * sizeof(float),
			(const void*)(vertex_array->_layout._offset_counts[i] * sizeof(float)));

		glEnableVertexAttribArray(vertex_array->_layout._shader_locations[i]);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer->_bufferID);
}

void bindVertexArray(VertexArray* vertex_array)
{
	glBindVertexArray(vertex_array->_vertex_array_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_array->_element_buffer->_bufferID);
}

void destroyVertexArray(VertexArray* array)
{
	free((void*)array->_layout._count_per_vertices);
	free((void*)array->_layout._normalised);
	free((void*)array->_layout._offset_counts);
	free((void*)array->_layout._shader_locations);

	free((void*)array);
}
