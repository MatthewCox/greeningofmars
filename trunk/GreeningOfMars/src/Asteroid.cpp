#include "Asteroid.h"

#include <stdlib.h>

#include <GL/freeglut.h>

Asteroid::Asteroid(void)
{
	position = Vector3f(0.0f);
	velocity = Vector3f(0.0f);
}

Asteroid::Asteroid(Vector3f p_position, Vector3f p_velocity)
{
	position = p_position;
	velocity = p_velocity;
}

Asteroid::~Asteroid(void)
{
}

void Asteroid::Update(float f_dt)
{
	position += velocity * f_dt;
}

void Asteroid::Draw()
{
	glPushMatrix();
	glTranslatef(position.X(), position.Y(), position.Z());

	HeightmapSphere::Draw();
	glPopMatrix();
}