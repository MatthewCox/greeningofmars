#include "ScreenManager.h"

#include "Screen.h"

ScreenManager* ScreenManager::thisInstance = new ScreenManager();

ScreenManager::ScreenManager(void)
{
	currentScreen = 0;
}

ScreenManager::~ScreenManager(void)
{
}

ScreenManager* ScreenManager::GetInstance()
{
	if (thisInstance == 0)
	{
		thisInstance = new ScreenManager();
	}
	return thisInstance;
}

void ScreenManager::Update(float f_dt)
{
	currentScreen->Update(f_dt);
}

void ScreenManager::Draw()
{
	currentScreen->Draw();
}

void ScreenManager::ChangeScreen(Screen* newScreen)
{
	if (currentScreen != 0)
	{
		currentScreen->Unload();
		delete currentScreen;
		currentScreen = 0;
	}
	newScreen->Load();
	currentScreen = newScreen;
}