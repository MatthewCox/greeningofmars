#include "ScreenChoice.h"

#include <stdlib.h>

#include <GL/freeglut.h>

#include "Camera.h"
#include "Mars.h"

#include "Panel.h"
#include "Label.h"
#include "Button.h"

#include "Screens.h"
#include "Settings.h"
#include "HUD.h"
#include "MouseHandler.h"

ScreenChoice::ScreenChoice(void)
{
}

ScreenChoice::~ScreenChoice(void)
{
}

void ScreenChoice::Update(float f_dt)
{
	mars->Update(f_dt);

	if (MouseHandler::Pressed(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);
		if (buttonChoice1->CheckClicked(mouseX, mouseY))
		{
			labelChoiceTitle->Name(buttonChoice1->Name());
		}
		if (buttonChoice2->CheckClicked(mouseX, mouseY))
		{
			labelChoiceTitle->Name(buttonChoice2->Name());
		}
		if (buttonChoice3->CheckClicked(mouseX, mouseY))
		{
			labelChoiceTitle->Name(buttonChoice3->Name());
		}
		if (buttonChoice4->CheckClicked(mouseX, mouseY))
		{
			labelChoiceTitle->Name(buttonChoice4->Name());
		}
	}
}

void ScreenChoice::Draw()
{
	camera->Display();

	mars->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);
	panelChoice->Draw();
		labelTitle->Draw();
		buttonChoice1->Draw();
		buttonChoice2->Draw();
		buttonChoice3->Draw();
		buttonChoice4->Draw();
	panelChoiceTitle->Draw();
		labelChoiceTitle->Draw();
	panelDescription->Draw();
	panelStat->Draw();

	buttonGo->Draw();
	HUD::End();
}

void ScreenChoice::Load()
{
	camera = new Camera(
		Vector3f(0.0f, 0.0f, 15.0f),
		0.0f, 0.0f);

	mars = new Mars();

	char* fontPath = Settings::UI::FontPath;

	float horzSpacing = Settings::View::Width / 40.0f;
	float vertSpacing = Settings::View::Height / 40.0f;

	panelChoice = new Panel(
		Vector2f(6 * horzSpacing, 6 * vertSpacing),
		Vector2f(28 * horzSpacing, 10 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	labelTitle = new Label(
		Vector2f(20 * horzSpacing, 7 * vertSpacing),
		"<STAGE NAME>", fontPath,
		Settings::UI::LabelColour,
		true);
	buttonChoice1 = new Button(
		Vector2f(7 * horzSpacing, 8 * vertSpacing),
		Vector2f(5 * horzSpacing, 5 * vertSpacing),
		"<CHOICE 1>", fontPath,
		Settings::UI::ButtonColour);
	buttonChoice2 = new Button(
		Vector2f(14 * horzSpacing, 8 * vertSpacing),
		Vector2f(5 * horzSpacing, 5 * vertSpacing),
		"<CHOICE 2>", fontPath,
		Settings::UI::ButtonColour);
	buttonChoice3 = new Button(
		Vector2f(21 * horzSpacing, 8 * vertSpacing),
		Vector2f(5 * horzSpacing, 5 * vertSpacing),
		"<CHOICE 3>", fontPath,
		Settings::UI::ButtonColour);
	buttonChoice4 = new Button(
		Vector2f(28 * horzSpacing, 8 * vertSpacing),
		Vector2f(5 * horzSpacing, 5 * vertSpacing),
		"<CHOICE 4>", fontPath,
		Settings::UI::ButtonColour);
	panelChoiceTitle = new Panel(
		Vector2f(6 * horzSpacing, 18 * vertSpacing),
		Vector2f(28 * horzSpacing, 4 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	labelChoiceTitle = new Label(
		Vector2f(20 * horzSpacing, 20 * vertSpacing),
		"Please choose a method.", fontPath,
		Settings::UI::LabelColour,
		true);
	panelDescription = new Panel(
		Vector2f(6 * horzSpacing, 24 * vertSpacing),
		Vector2f(8 * horzSpacing, 10 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	panelStat = new Panel(
		Vector2f(16 * horzSpacing, 24 * vertSpacing),
		Vector2f(8 * horzSpacing, 10 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	buttonGo = new Button(
		Vector2f(26 * horzSpacing, 24 * vertSpacing),
		Vector2f(8 * horzSpacing, 10 * vertSpacing),
		"GO!", fontPath,
		Settings::UI::ButtonColour);
}

void ScreenChoice::Unload()
{
	delete camera;
	delete mars;

	delete panelChoice;
	delete labelTitle;
	delete buttonChoice1;
	delete buttonChoice2;
	delete buttonChoice3;
	delete buttonChoice4;
	delete panelChoiceTitle;
	delete labelChoiceTitle;
	delete panelDescription;
	delete panelStat;
	delete buttonGo;
}