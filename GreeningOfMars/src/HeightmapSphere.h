#pragma once

#include "TextureLoader\TextureLoader.h"
#include "Shader.h"

class HeightmapSphere
{
public:
	HeightmapSphere(void);
	~HeightmapSphere(void);

	void Draw();
private:
	TextureLoader* texLoader;
	glTexture* texture;
	GLUquadric* quadric;
	Shader* shader;
};
