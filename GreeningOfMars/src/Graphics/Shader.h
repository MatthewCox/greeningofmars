#pragma once
/****************************************************************************
* 																			*
* Shader																	*
* 																			*
* Handles the loading, compilation, validation, and use of GLSL shaders		*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class CShader
{
public:
	/*
	 * Default constructor
	 * If you use this, you will later have to call Init to actually set up the shader for use
	 */
	CShader(void);
	/*
	 * Parameterized constructor
	 * Takes in the paths to a vertex and fragment shader, and loads, compiles, and validates them
	 */
	CShader(const char *vertexShaderPath, const char *fragmentShaderPath);
	
	/*
	 * Destructor
	 * Unloads the vertex and fragment shaders from the GPU, and deletes them from memory
	 */
	~CShader(void);

	// Takes in the paths to a vertex and fragment shader, and loads, compiles, and validates them
	void Init(const char *vertexShaderPath, const char *fragmentShaderPath);
	// Tells the GPU to use this shader for subsequent drawing operations
	void Bind();
	// Tells the GPU to stop using this shader for subsequent drawing operations
	void Unbind();
	// Returns the Id of the shader program on the GPU, for use with glGetUniformLocation and other such functions
	unsigned int Id();

private:
	unsigned int id;
	unsigned int vertexProgram;
	unsigned int fragmentProgram;

};
