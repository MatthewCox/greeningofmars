#pragma once

#include "GameObject.h"

#include "TextureLoader/TextureLoader.h"
#include "Shader.h"

class HeightmapSphere : public GameObject
{
public:
	HeightmapSphere(void);
	~HeightmapSphere(void);

	void Update(float f_dt);
	void Draw();

private:
	TextureLoader* texLoader;
	glTexture* texture;
	GLUquadric* quadric;
	Shader* shader;
};
