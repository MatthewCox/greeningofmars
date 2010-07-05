#pragma once

#include "GameObject.h"

#include "../Core/TextureLoader/TextureLoader.h"
#include "../Graphics/Shader.h"

class WaterSphere : public GameObject
{
public:
	WaterSphere(void);
	~WaterSphere(void);

	void Update(float f_dt);
	void Draw();

	float Radius() const;
	void Radius(float p_radius);

private:
	float time;
	float radius;
	TextureLoader* texLoader;
	glTexture* texture;
	GLUquadric* quadric;
	Shader* shader;
};
