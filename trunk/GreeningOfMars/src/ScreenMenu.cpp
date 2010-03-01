#include "ScreenMenu.h"

#include <vector>
#include <windows.h>

#include <GL/GL.h>

#include "Screens.h"
#include "Settings.h"
#include "HUD.h"
#include "MouseHandler.h"
#include "SwishyButton.h"
#include "HeightmapSphere.h"

ScreenMenu::ScreenMenu(void)
{
}

ScreenMenu::~ScreenMenu(void)
{
}

void ScreenMenu::Update(float f_dt)
{
	for (std::vector<Button*>::iterator i = buttons->begin(); i != buttons->end(); ++i)
	{
		(*i)->Update(f_dt);
	}

	if (MouseHandler::GetState(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);
		if (buttonStart->CheckClicked(mouseX, mouseY))
		{
			ScreenManager* screenManager = ScreenManager::GetInstance();
			screenManager->ChangeScreen(new ScreenGame());
		}
		else if (buttonQuit->CheckClicked(mouseX, mouseY))
		{
			Settings::Save(".\\settings.ini");
			exit(0);
		}
	}
}

void ScreenMenu::Draw()
{
	glTranslatef(0.0f, 0.0f, -100.0f);
	sphere->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);

	for (std::vector<Button*>::iterator i = buttons->begin(); i != buttons->end(); ++i)
	{
		(*i)->Draw();
	}

	HUD::End();
}

void ScreenMenu::Load()
{
	buttons = new std::vector<Button*>();

	buttonStart = new SwishyButton(
		0.0f, (float)(Settings::View::Height / 2) - 50.0f,
		200.0f, 50.0f,
		"Start", "C:\\Windows\\Fonts\\tahoma.ttf",
		0);
	buttons->push_back(buttonStart);

	buttonQuit = new SwishyButton(
		0.0f, (float)(Settings::View::Height / 2) + 50.0f,
		200.0f, 50.0f,
		"Quit", "C:\\Windows\\Fonts\\tahoma.ttf",
		0);
	buttons->push_back(buttonQuit);

	sphere = new HeightmapSphere();
}

void ScreenMenu::Unload()
{
	delete buttonStart;
	delete buttonQuit;
	delete buttons;
	delete sphere;
}