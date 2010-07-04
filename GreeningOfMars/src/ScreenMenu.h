#pragma once

#include "Screen.h"

#include <vector>

#include "Mars.h"
#include "Camera.h"
#include "SwishyButton.h"
#include "Label.h"

class ScreenMenu : public CScreen
{
public:
	ScreenMenu(void);
	~ScreenMenu(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Mars* mars;
	Camera* camera;

	std::vector<Button*>* buttons;
	Label* labelThe;
	Label* labelGreening;
	Label* labelOf;
	Label* labelMars;
	SwishyButton* buttonStart;
	SwishyButton* buttonQuit;
	
	bool transitioning;
	float moveSpeed;
};
