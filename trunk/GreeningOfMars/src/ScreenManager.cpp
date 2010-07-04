#include "ScreenManager.h"

#include <vector>

#include "Screen.h"

CScreenManager* CScreenManager::thisInstance = new CScreenManager();

CScreenManager::CScreenManager(void)
{
}

CScreenManager::~CScreenManager(void)
{
}

CScreenManager* CScreenManager::GetInstance()
{
	if (thisInstance == 0)
	{
		thisInstance = new CScreenManager();
	}
	return thisInstance;
}

void CScreenManager::Update(float f_dt)
{
	// Update only the top-most screen in the stack
	screens.back()->Update(f_dt);
}

void CScreenManager::Draw()
{
	// Draw all screens in the stack, starting from the bottom
	for (std::vector<CScreen*>::iterator i = screens.begin(); i != screens.end(); ++i)
	{
		(*i)->Draw();
	}
}

void CScreenManager::ChangeScreen(CScreen* newScreen)
{
	if (!screens.empty())
	{
		PopScreen();
	}

	PushScreen(newScreen);
}

void CScreenManager::PushScreen(CScreen* newScreen)
{
	screens.push_back(newScreen);
	screens.back()->Load();
}

void CScreenManager::PopScreen()
{
	screens.back()->Unload();
	screens.pop_back();
}

void CScreenManager::Unload()
{
	while (!screens.empty())
	{
		PopScreen();
	}
}