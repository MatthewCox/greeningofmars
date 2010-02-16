#include "ScreenTest.h"

#include "Settings.h"

ScreenTest::ScreenTest(void)
{
	map = 0;
}

ScreenTest::~ScreenTest(void)
{
}

void ScreenTest::Update(float f_dt)
{

}

void ScreenTest::Draw()
{
	map->Draw();
}

void ScreenTest::Load()
{
	map = new Map();
	map->Load(".\\land.txt");
}

void ScreenTest::Unload()
{
	delete map;
}