#pragma once

struct Shader {
	unsigned int _shader_program_id;
};

typedef struct Shader Shader;

Shader		loadAndCompileShaders(const char* vertex_shader_src, const char* fragment_shader_src);

void		useShader(Shader* shader);

void		setUniformMatrix4f(Shader shader, const char* name, void* value);

void		setUniformFloat(Shader shader, const char* name, void* value);
void		setUniformFloat2(Shader shader, const char* name, void* value);
void		setUniformFloat3(Shader shader, const char* name, void* value);
void		setUniformFloat4(Shader shader, const char* name, void* value);

void		setUniformInt(Shader shader, const char* name, int value);
void		setUniformIntArray(Shader shader, const char* name, void* value);
