#include "shader.h"
#include <stdio.h>
#include <glad/gl.h>

Shader loadAndCompileShaders(const char* vertex_shader_src, const char* fragment_shader_src)
{
	const GLuint handleVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(handleVertex, 1, &vertex_shader_src, (void*)0);
	glCompileShader(handleVertex);

	const char infoLog[512];
	int success;
	glGetShaderiv(handleVertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(handleVertex, 512, NULL, infoLog);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:\n %s\n", infoLog);
	};

	const GLuint handleFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(handleFragment, 1, &fragment_shader_src, (void*)0);
	glCompileShader(handleFragment);

	glGetShaderiv(handleFragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(handleFragment, 512, NULL, infoLog);
		printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED:\n %s\n5", infoLog);
	};

	Shader shader;
	shader._shader_program_id = glCreateProgram();
	glAttachShader(shader._shader_program_id, handleVertex);
	glAttachShader(shader._shader_program_id, handleFragment);
	glLinkProgram(shader._shader_program_id);
	glUseProgram(shader._shader_program_id);

	return shader;
}

void useShader(Shader* shader)
{
	glUseProgram(shader->_shader_program_id);
}

void setUniformMatrix4f(Shader shader, const char* name, void* value)
{
	int uniform = glGetUniformLocation(shader._shader_program_id, name);
	if (uniform == -1) {
		fprintf(stderr, "Shader not found!");
		return;
	}
	glUniformMatrix4fv(uniform, 1, GL_FALSE, value);
}

void setUniformFloat(Shader shader, const char* name, void* value)
{
}

void setUniformFloat2(Shader shader, const char* name, void* value)
{
}

void setUniformFloat3(Shader shader, const char* name, void* value)
{
}

void setUniformFloat4(Shader shader, const char* name, void* value)
{
}

void setUniformInt(Shader shader, const char* name, int value)
{
	int uniform = glGetUniformLocation(shader._shader_program_id, name);
	if (uniform == -1) {
		fprintf(stderr, "Shader not found!\n");
		return;
	}
	glUniform1i(uniform, value);
}

void setUniformIntArray(Shader shader, const char* name, void* value)
{
}
