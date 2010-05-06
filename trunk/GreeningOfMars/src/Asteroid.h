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

	void Velocity(Vector3f p_velocity);

	bool Finished();

private:
	Vector3f velocity;
	bool finished;
};
