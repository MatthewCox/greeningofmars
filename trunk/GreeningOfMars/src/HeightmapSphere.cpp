#include "HeightmapSphere.h"

#include <Windows.h>

#include <GL/GLU.h>

HeightmapSphere::HeightmapSphere(void)
{
	texture = new glTexture;
	texLoader = new TextureLoader();
	texLoader->LoadTextureFromDisk(".\\MarsHeight.bmp", texture);
	quadric = gluNewQuadric();
}

HeightmapSphere::~HeightmapSphere(void)
{
	texLoader->FreeTexture(texture);
	delete texLoader;
	gluDeleteQuadric(quadric);
}

void HeightmapSphere::Draw()
{
	glPushMatrix();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		gluQuadricTexture(quadric, GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, texture->TextureID);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluSphere(quadric, 5, 36, 36);
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}