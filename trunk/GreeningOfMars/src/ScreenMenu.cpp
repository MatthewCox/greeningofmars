#include <iostream>

#include "ScreenMenu.h"

#include "Settings.h"
#include "HUD.h"
#include "MouseHandler.h"

ScreenMenu::ScreenMenu(void)
{
	buttonQuit = 0;
	sphere = 0;
}

ScreenMenu::~ScreenMenu(void)
{
}

void ScreenMenu::Update(float f_dt)
{
	buttonQuit->Update(f_dt);

	if (MouseHandler::GetState(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);
		if (buttonQuit->CheckClicked(mouseX, mouseY))
		{
			exit(0);
		}
	}
}

void ScreenMenu::Draw()
{
	sphere->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);

	buttonQuit->Draw();

	HUD::End();
}

void ScreenMenu::Load()
{
	buttonQuit = new SwishyButton(
		0.0f, (float)(Settings::View::Height / 2) - 25.0f,
		200.0f, 50.0f,
		"Quit", "C:\\Windows\\Fonts\\tahoma.ttf",
		0);
	sphere = new HeightmapSphere();
}

void ScreenMenu::Unload()
{
	delete buttonQuit;
	delete sphere;
}