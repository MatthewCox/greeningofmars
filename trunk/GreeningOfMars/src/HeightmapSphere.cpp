#include "HeightmapSphere.h"

#include <Windows.h>
#include <GL/GLU.h>

HeightmapSphere::HeightmapSphere(void)
{
}

HeightmapSphere::~HeightmapSphere(void)
{
}

void HeightmapSphere::Draw()
{
	glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
	GLUquadric* quadric = gluNewQuadric();
	gluSphere(quadric, 5, 36, 36);
}