#pragma once

#include "Screen.h"

class ScreenManager
{
private:
	static ScreenManager* thisInstance;
	Screen* currentScreen;

public:
	ScreenManager(void);
	~ScreenManager(void);

	static ScreenManager* GetInstance();

	void Update(float f_dt);
	void Draw();

	void ChangeScreen(Screen* newScreen);
};
