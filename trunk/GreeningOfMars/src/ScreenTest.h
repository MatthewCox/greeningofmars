#pragma once

#include "Screen.h"

#include "Map.h"

class ScreenTest : public Screen
{
public:
	ScreenTest(void);
	~ScreenTest(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Map* map;
};
