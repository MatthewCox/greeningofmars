#pragma once

#include "DrawableObject.h"

#include "TextureLoader\TextureLoader.h"
#include "Shader.h"

class HeightmapSphere : public DrawableObject
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
