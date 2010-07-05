#include "WaterSphere.h"

#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

#include "../Core/TextureLoader/TextureLoader.h"
#include "../Graphics/Shader.h"

WaterSphere::WaterSphere(void)
{
	time = 0.0f;
	texture = new glTexture;
	texLoader = new TextureLoader();
	texLoader->LoadTextureFromDisk(".\\Resources\\WaterNormal.bmp", texture);
	quadric = gluNewQuadric();
	shader = new Shader(".\\Shaders\\water.vert", ".\\Shaders\\water.frag");
}

WaterSphere::~WaterSphere(void)
{
	texLoader->FreeTexture(texture);
	delete texLoader;
	gluDeleteQuadric(quadric);
	delete shader;
}

void WaterSphere::Update(float f_dt)
{
	time += f_dt;
}

void WaterSphere::Draw()
{
	shader->Bind();
	glPushMatrix();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		gluQuadricTexture(quadric, GL_TRUE);
		gluQuadricNormals(quadric, GL_TRUE);
		glActiveTexture(GL_TEXTURE0);
		int textureLocation = glGetUniformLocation(shader->Id(), "waterNormal");
		glUniform1i(textureLocation, 0);
		int timeLocation = glGetUniformLocation(shader->Id(), "Time");
		glUniform1f(timeLocation, time);
		glBindTexture(GL_TEXTURE_2D, texture->TextureID);
		glActiveTexture(GL_TEXTURE0);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluSphere(quadric, radius, 72, 72);
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
	shader->Unbind();
}

float WaterSphere::Radius() const
{
	return radius;
}

void WaterSphere::Radius(float p_radius)
{
	radius = p_radius;
}