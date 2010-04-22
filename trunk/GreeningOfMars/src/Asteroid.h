#pragma once

#include "HeightmapSphere.h"

#include "Vector3f.h"

class Asteroid : public HeightmapSphere
{
public:
	Asteroid(void);
	Asteroid(Vector3f p_position);
	~Asteroid(void);

	void Draw();

private:
	Vector3f position;
};
