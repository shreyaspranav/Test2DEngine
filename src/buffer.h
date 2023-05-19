#pragma once
#include <stdbool.h>

enum BufferType { BufferType_FLOAT_BUFFER, BufferType_ELEMENT_BUFFER };

typedef enum BufferType BufferType;

struct BufferLayout {
	unsigned short _count;
	unsigned short _index;

	unsigned short* _shader_locations;
	unsigned short* _count_per_vertices;
	unsigned short* _offset_counts;

	bool* _normalised;
};

struct Buffer {
	unsigned int _bufferID;
	BufferType _bufferType;

	unsigned int _count, _size_per_value;
};

typedef struct BufferLayout BufferLayout;
typedef struct Buffer Buffer;

struct VertexArray {
	Buffer* _vertex_buffer;
	Buffer* _element_buffer;

	BufferLayout _layout;

	unsigned int _vertex_array_id;
};

typedef struct VertexArray VertexArray;

// BufferLayout API -------------------------------------------------------------
// ------------------------------------------------------------------------------
BufferLayout	createBufferLayout(unsigned short shader_loc_count);
void			addBufferElement(BufferLayout* layout, unsigned short shader_location, unsigned short count_per_vertex, unsigned short offset_count, bool normalised);
short			getBufferElementCount(BufferLayout* layout);

// Buffer API--------------------------------------------------------------------
// ------------------------------------------------------------------------------
Buffer*			createBuffer(BufferType type, unsigned int max_count, void* data);
void			setBufferData(Buffer* buffer, void* data, unsigned int offset_count, unsigned int count);
void			destroyBuffer(Buffer* buffer);

BufferType		getBufferType(Buffer* buffer);
unsigned int	getBufferCount(Buffer* buffer);

// VertexArray API --------------------------------------------------------------
// ------------------------------------------------------------------------------
VertexArray*	createVertexArray(BufferLayout* buffer_layout);
void			finalize(VertexArray* vertex_array, Buffer* vertex_buffer, Buffer* element_buffer);
void			bindVertexArray(VertexArray* vertex_array);
void			destroyVertexArray(VertexArray* array);
