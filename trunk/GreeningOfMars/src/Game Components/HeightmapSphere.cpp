#include "HeightmapSphere.h"

#include <stdlib.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

#include "../Core/TextureLoader/TextureLoader.h"
#include "../Graphics/Shader.h"

HeightmapSphere::HeightmapSphere(void)
{
	texture = new glTexture;
	texLoader = new TextureLoader();
	texLoader->LoadTextureFromDisk(".\\Resources\\MarsHeight.bmp", texture);
	quadric = gluNewQuadric();
	shader = new Shader(".\\Shaders\\sphereDeform.vert", ".\\Shaders\\sphereDeform.frag");
}

HeightmapSphere::~HeightmapSphere(void)
{
	texLoader->FreeTexture(texture);
	delete texLoader;
	gluDeleteQuadric(quadric);
	delete shader;
}

void HeightmapSphere::Update(float f_dt)
{

}

void HeightmapSphere::Draw()
{
	shader->Bind();
	glPushMatrix();
		glTranslatef(position.X(), position.Y(), position.Z());
		gluQuadricTexture(quadric, GL_TRUE);
		gluQuadricNormals(quadric, GL_TRUE);
		glActiveTexture(GL_TEXTURE0);
		int textureLocation = glGetUniformLocation(shader->Id(), "marsHeightmap");
		glUniform1i(textureLocation, 0);
		int radiusLocation = glGetUniformLocation(shader->Id(), "radius");
		glUniform1f(radiusLocation, radius);
		glBindTexture(GL_TEXTURE_2D, texture->TextureID);
		glActiveTexture(GL_TEXTURE0);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		gluSphere(quadric, radius, 72, 72);
		glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
	shader->Unbind();
}

float HeightmapSphere::Radius() const
{
	return radius;
}

void HeightmapSphere::Radius(float p_radius)
{
	radius = p_radius;
}