#include "Asteroid.h"

#include <stdlib.h>

#include <GL\freeglut.h>

Asteroid::Asteroid(void)
{
	position = Vector3f(0.0f, 0.0f, 0.0f);
}

Asteroid::~Asteroid(void)
{
}

void Asteroid::Draw()
{
	glPushMatrix();
	glTranslatef(position.X(), position.Y(), position.Z());

	HeightmapSphere::Draw();
	glPopMatrix();
}