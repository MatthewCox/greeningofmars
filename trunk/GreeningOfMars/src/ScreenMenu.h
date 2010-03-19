#pragma once

#include "Screen.h"

#include <vector>

#include "SwishyButton.h"
#include "Label.h"
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
	std::vector<Button*>* buttons;
	Label* labelThe;
	Label* labelGreening;
	Label* labelOf;
	Label* labelMars;
	SwishyButton* buttonStart;
	SwishyButton* buttonQuit;
	HeightmapSphere* sphere;
	
	float planetPosition;
	bool transitioning;
};
