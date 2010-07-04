#pragma once

#include <vector>

#include "Screen.h"

class CScreenManager
{
public:
	~CScreenManager(void);

	static CScreenManager* GetInstance();

	void Update(float f_dt);
	void Draw();

	void ChangeScreen(CScreen* newScreen);
	void PushScreen(CScreen* newScreen);
	void PopScreen();

	void Unload();

protected:
	CScreenManager(void);

private:
	static CScreenManager* thisInstance;

	std::vector<CScreen*> screens;
};
