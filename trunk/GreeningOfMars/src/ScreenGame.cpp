#include "ScreenGame.h"

#include <windows.h>

#include <GL/GL.h>

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
	map->Draw();
}

void ScreenGame::Load()
{
	sphere = new HeightmapSphere();
	map = new Map();
	map->Load("land.txt");
}

void ScreenGame::Unload()
{
	delete sphere;
	delete map;
}