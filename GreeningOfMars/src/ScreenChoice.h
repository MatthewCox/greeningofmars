#pragma once

#include "Screen.h"

#include "HeightmapSphere.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class ScreenChoice : public Screen
{
public:
	ScreenChoice(void);
	~ScreenChoice(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	HeightmapSphere* sphere;
	Panel* panelChoice;
	Panel* panelTitle;
	Label* labelTitle;
	Panel* panelDescription;
	Panel* panelStat;
	Button* buttonGo;
};
