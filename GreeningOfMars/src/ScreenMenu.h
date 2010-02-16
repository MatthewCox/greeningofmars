#pragma once

#include "Screen.h"

#include "SwishyButton.h"
#include "HeightmapSphere.h"

class ScreenMenu : public Screen
{
public:
	ScreenMenu(void);
	~ScreenMenu(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	SwishyButton* buttonQuit;
	HeightmapSphere* sphere;
};
