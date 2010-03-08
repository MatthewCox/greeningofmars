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
}

void ScreenGame::Unload()
{
	delete sphere;
}