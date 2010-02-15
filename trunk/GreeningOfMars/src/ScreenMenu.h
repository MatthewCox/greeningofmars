#pragma once

#include "Screen.h"

#include "SwishyButton.h"

class ScreenMenu : public Screen
{
public:
	ScreenMenu(void);
	~ScreenMenu(void);

	void Update(float p_dt);
	void Draw();

	void Load();
	void Unload();

private:
	SwishyButton* buttonTest;
};
