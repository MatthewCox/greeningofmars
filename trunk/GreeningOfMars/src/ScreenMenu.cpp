#include "ScreenMenu.h"

#include <vector>
#include <stdlib.h>

#include <GL\freeglut.h>

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

	if (!transitioning)
	{
		if (MouseHandler::Pressed(0))
		{
			int mouseX = 0;
			int mouseY = 0;
			MouseHandler::GetPosition(mouseX, mouseY);
			if (buttonStart->CheckClicked(mouseX, mouseY))
			{
				transitioning = true;
				buttonStart->SwishOff();
				buttonQuit->SwishOff();
			}
			else if (buttonQuit->CheckClicked(mouseX, mouseY))
			{
				Settings::Save(".\\settings.ini");
				exit(0);
			}
		}
	}
	else
	{
		if (planetPosition <= -10.0f)
		{
			planetPosition += 50.0f * f_dt;
		}
		else
		{
			ScreenManager* screenManager = ScreenManager::GetInstance();
			screenManager->ChangeScreen(new ScreenChoice());
		}
	}
}

void ScreenMenu::Draw()
{
	if (planetPosition > -10.0f)
	{
		glTranslatef(0.0f, 0.0f, -10.0f);
	}
	else
	{
		glTranslatef(0.0f, 0.0f, planetPosition);
	}
	sphere->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	labelThe->Draw();
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	labelGreening->Draw();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	labelOf->Draw();
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	labelMars->Draw();

	for (std::vector<Button*>::iterator i = buttons->begin(); i != buttons->end(); ++i)
	{
		glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
		(*i)->Draw();
	}

	HUD::End();
}

void ScreenMenu::Load()
{
	float titleSpacing = Settings::View::Height / 25.0f;
	labelThe = new Label(
		Vector2f(Settings::View::Width / 2.0f, titleSpacing),
		"The", "C:\\Windows\\Fonts\\tahoma.ttf",
		true);
	labelGreening = new Label(
		Vector2f(Settings::View::Width / 2.0f, 2 * titleSpacing),
		"Greening", "C:\\Windows\\Fonts\\tahoma.ttf",
		true);
	labelOf = new Label(
		Vector2f(Settings::View::Width / 2.0f, 3 * titleSpacing),
		"Of", "C:\\Windows\\Fonts\\tahoma.ttf",
		true);
	labelMars = new Label(
		Vector2f(Settings::View::Width / 2.0f, 4 * titleSpacing),
		"Mars", "C:\\Windows\\Fonts\\tahoma.ttf",
		true);

	transitioning = false;

	buttons = new std::vector<Button*>();

	buttonStart = new SwishyButton(
		Vector2f(-20.0f, (float)(Settings::View::Height / 2) - 45.0f),
		Vector2f(110.0f, 40.0f),
		"Start", "C:\\Windows\\Fonts\\tahoma.ttf",
		0);
	buttonStart->SwishOn();
	buttons->push_back(buttonStart);

	buttonQuit = new SwishyButton(
		Vector2f(-20.0f, (float)(Settings::View::Height / 2) + 5.0f),
		Vector2f(100.0f, 40.0f),
		"Quit", "C:\\Windows\\Fonts\\tahoma.ttf",
		0);
	buttonQuit->SwishOn();
	buttons->push_back(buttonQuit);

	sphere = new HeightmapSphere();

	planetPosition = -200.0f;
}

void ScreenMenu::Unload()
{
	delete labelThe;
	delete labelGreening;
	delete labelOf;
	delete labelMars;
	delete buttonStart;
	delete buttonQuit;
	delete buttons;
	delete sphere;
}