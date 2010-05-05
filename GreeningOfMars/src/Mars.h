#pragma once

#include "GameObject.h"

#include "CConditions.h"
#include "HeightmapSphere.h"
#include "WaterSphere.h"

class Mars : public GameObject
{
public:
	Mars(void);
	~Mars(void);

	void Update(float f_dt);
	void Draw();

	CConditions* Conditions();
	HeightmapSphere* Sphere();

private:
	float angle;
	CConditions *conditions;
	HeightmapSphere *heightmapSphere;
	WaterSphere *waterSphere;
};
