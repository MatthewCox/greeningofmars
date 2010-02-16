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
	glColor4f(0.5f, 0.2f, 0.05f, 1.0f);
	GLUquadric* quadric = gluNewQuadric();
	gluSphere(quadric, 5, 36, 36);
}