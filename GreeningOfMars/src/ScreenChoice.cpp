#include "ScreenChoice.h"

#include <stdlib.h>

#include <GL/freeglut.h>

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
	if (MouseHandler::Pressed(0))
	{
		int mouseX = 0;
		int mouseY = 0;
		MouseHandler::GetPosition(mouseX, mouseY);
		if (buttonGo->CheckClicked(mouseX, mouseY))
		{
			ScreenManager* screenManager = ScreenManager::GetInstance();
			screenManager->ChangeScreen(new ScreenGame());
		}
	}
}

void ScreenChoice::Draw()
{
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, -10.0f);
		sphere->Draw();
	glPopMatrix();

	HUD::Start(Settings::View::Width, Settings::View::Height);
	panelChoice->Draw();
		labelChoiceTitle->Draw();
		buttonChoice1->Draw();
		buttonChoice2->Draw();
		buttonChoice3->Draw();
		buttonChoice4->Draw();
	panelTitle->Draw();
		labelTitle->Draw();
	panelDescription->Draw();
	panelStat->Draw();

	buttonGo->Draw();
	HUD::End();
}

void ScreenChoice::Load()
{
	sphere = new HeightmapSphere();

	char* fontPath = Settings::UI::FontPath;

	float horzSpacing = Settings::View::Width / 40.0f;
	float vertSpacing = Settings::View::Height / 40.0f;

	panelChoice = new Panel(
		Vector2f(6 * horzSpacing, 6 * vertSpacing),
		Vector2f(28 * horzSpacing, 10 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	labelChoiceTitle = new Label(
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
	panelTitle = new Panel(
		Vector2f(6 * horzSpacing, 18 * vertSpacing),
		Vector2f(28 * horzSpacing, 4 * vertSpacing),
		20.0f,
		Settings::UI::PanelColour);
	labelTitle = new Label(
		Vector2f(20 * horzSpacing, 20 * vertSpacing),
		"<CHOICE TITLE>", fontPath,
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
	delete sphere;
	delete panelChoice;
	delete labelChoiceTitle;
	delete buttonChoice1;
	delete buttonChoice2;
	delete buttonChoice3;
	delete buttonChoice4;
	delete panelTitle;
	delete labelTitle;
	delete panelDescription;
	delete panelStat;
	delete buttonGo;
}