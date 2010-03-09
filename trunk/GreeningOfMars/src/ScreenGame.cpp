#include "ScreenGame.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include "Settings.h"

ScreenGame::ScreenGame(void)
{
}

ScreenGame::~ScreenGame(void)
{
}

void ScreenGame::Update(float f_dt)
{

}

void ScreenGame::Draw()
{
	glTranslatef(0.0f, 0.0f, -10.0f);
	sphere->Draw();
}

void ScreenGame::Load()
{
	sphere = new HeightmapSphere();
	GLfloat DiffuseLight[] = {1.0, 1.0, 1.0};
	GLfloat AmbientLight[] = {0.0, 0.0, 0.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	GLfloat LightPosition[] = {0.0, 1.0, 1.0, 0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
}

void ScreenGame::Unload()
{
	delete sphere;
}