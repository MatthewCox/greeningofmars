#include "Asteroid.h"

#include <stdlib.h>

#include <GL/freeglut.h>

Asteroid::Asteroid(void)
{
	position = Vector3f(0.0f);
	velocity = Vector3f(0.0f);
	finished = false;
}

Asteroid::Asteroid(Vector3f p_position, Vector3f p_velocity)
{
	position = p_position;
	velocity = p_velocity;
	finished = false;
}

Asteroid::~Asteroid(void)
{
}

void Asteroid::Update(float f_dt)
{
	if (!finished && position.length() >= 2.0f)
	{
		position += velocity * f_dt;
	}
	else if (!finished && velocity != Vector3f(0.0f))
	{
		position = Vector3f(0.0f);
		velocity = Vector3f(0.0f);
		finished = true;
	}
}

void Asteroid::Draw()
{
	glPushMatrix();
	glTranslatef(position.X(), position.Y(), position.Z());

	HeightmapSphere::Draw();
	glPopMatrix();
}

void Asteroid::Velocity(Vector3f p_velocity)
{
	velocity = p_velocity;
}

bool Asteroid::Finished()
{
	return finished;
}