#pragma once

#include "HeightmapSphere.h"

#include "Vector3f.h"

class Asteroid : public HeightmapSphere
{
public:
	Asteroid(void);
	Asteroid(Vector3f p_position, Vector3f p_velocity);
	~Asteroid(void);

	void Update(float f_dt);
	void Draw();

private:
	Vector3f velocity;
};
