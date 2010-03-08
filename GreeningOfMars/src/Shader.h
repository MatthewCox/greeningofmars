#pragma once

class Shader
{
public:
	Shader(void);
	Shader(const char *vertexShaderPath, const char *fragmentShaderPath);
	~Shader(void);

	void Init(const char *vertexShaderPath, const char *fragmentShaderPath);

	void Bind();
	void Unbind();

	unsigned int Id();

private:
	unsigned int id;
	unsigned int vertexProgram;
	unsigned int fragmentProgram;
};
