#include "Mars.h"

#include <GL/freeglut.h>

Mars::Mars(void)
{
	conditions = new CConditions();
	heightmapSphere = new HeightmapSphere();
	waterSphere = new WaterSphere();
	heightmapSphere->Radius(5.0f);
	waterSphere->Radius(conditions->GetWaterLevel());
}

Mars::~Mars(void)
{
	delete conditions;
	delete heightmapSphere;
	delete waterSphere;
}

void Mars::Update(float f_dt)
{
	heightmapSphere->Update(f_dt);
	waterSphere->Update(f_dt);
	waterSphere->Radius(conditions->GetWaterLevel());
}

void Mars::Draw()
{
	glPushMatrix();
		glTranslatef(
			position.X(),
			position.Y(),
			position.Z());
		glColor3f(1.0f, 0.8f, 0.7f);
		heightmapSphere->Draw();
		waterSphere->Draw();
	glPopMatrix();
}

CConditions* Mars::Conditions()
{
	return conditions;
}

HeightmapSphere* Mars::Sphere()
{
	return heightmapSphere;
}