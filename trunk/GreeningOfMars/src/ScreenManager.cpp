#include "ScreenManager.h"

#include "Screen.h"

ScreenManager* ScreenManager::thisInstance = new ScreenManager();

ScreenManager::ScreenManager(void)
{
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

void ScreenManager::Update(float p_dt)
{
	currentScreen->Update(p_dt);
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
	}
	newScreen->Load();
	currentScreen = newScreen;
}