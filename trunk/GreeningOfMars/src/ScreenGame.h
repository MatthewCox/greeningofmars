#pragma once

#include "Screen.h"

#include "HeightmapSphere.h"

class ScreenGame : public Screen
{
public:
	ScreenGame(void);
	~ScreenGame(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	HeightmapSphere* sphere;
};
