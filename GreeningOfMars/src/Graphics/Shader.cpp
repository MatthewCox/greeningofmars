#include "Shader.h"

#include <stdlib.h>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

#include "../Core/Files.h"

/*
 * Validates the (compiled) shader supplied to it
 * Outputs any errors to the standard error buffer
 */
static void ValidateShader(GLuint shader, const char* file = 0)
{
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	GLsizei length = 0;

	glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);
	if (length > 0)
	{
		std::cerr << "Shader " << shader << " (" << (file?file:"") << ") compile error: " << buffer << std::endl;
	}
}

/*
 * Validates the linked vertex and fragment shader programs
 * Outputs any errors to the standard error buffer
 */
static void ValidateProgram(GLuint program)
{
	const unsigned int BUFFER_SIZE = 512;
	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);
	GLsizei length = 0;

	glGetShaderInfoLog(program, BUFFER_SIZE, &length, buffer);
	if (length > 0)
	{
		std::cerr << "Program " << program << " link error: " << buffer << std::endl;
	}

	glValidateProgram(program);
	GLint status;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);

	if (status == GL_FALSE)
	{
		std::cerr << "Error validating shader " << program << std::endl;
	}
}

CShader::CShader(void)
{
}

CShader::CShader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
	id = 0;
	vertexProgram = 0;
	fragmentProgram = 0;
	Init(vertexShaderPath, fragmentShaderPath);
}

CShader::~CShader(void)
{
	glDetachShader(id, vertexProgram);
	glDetachShader(id, fragmentProgram);
	
	glDeleteShader(vertexProgram);
	glDeleteShader(fragmentProgram);
	glDeleteProgram(id);
}

void CShader::Init(const char *vertexShaderPath, const char *fragmentShaderPath)
{
	vertexProgram = glCreateShader(GL_VERTEX_SHADER);
	fragmentProgram = glCreateShader(GL_FRAGMENT_SHADER);
	const char* vertexShaderText = Files::ReadText(vertexShaderPath);
	const char* fragmentShaderText = Files::ReadText(fragmentShaderPath);

	if (vertexShaderText == NULL || fragmentShaderText == NULL)
	{
		std::cerr << "Either vertex shader or fragment shader file not found." << std::endl;
		return;
	}

	glShaderSource(vertexProgram, 1, &vertexShaderText, 0);
	glShaderSource(fragmentProgram, 1, &fragmentShaderText, 0);

	glCompileShader(vertexProgram);
	ValidateShader(vertexProgram, vertexShaderPath);
	glCompileShader(fragmentProgram);
	ValidateShader(fragmentProgram, fragmentShaderPath);

	id = glCreateProgram();
	glAttachShader(id, vertexProgram);
	glAttachShader(id, fragmentProgram);
	glLinkProgram(id);
	ValidateProgram(id);
}

void CShader::Bind()
{
	glUseProgram(id);
}

void CShader::Unbind()
{
	glUseProgram(0);
}

unsigned int CShader::Id()
{
	return id;
}