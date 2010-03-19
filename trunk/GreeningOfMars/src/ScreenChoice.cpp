#include "ScreenChoice.h"

#include <stdlib.h>

#include <GL\freeglut.h>

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
	glTranslatef(0.0f, 0.0f, -10.0f);
	sphere->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);
	glColor4f(0.0f, 0.2f, 0.4f, 0.8f);
	panelChoice->Draw();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		labelChoiceTitle->Draw();
		glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
		buttonChoice1->Draw();
		glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
		buttonChoice2->Draw();
		glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
		buttonChoice3->Draw();
		glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
		buttonChoice4->Draw();
	glColor4f(0.0f, 0.2f, 0.4f, 0.8f);
	panelTitle->Draw();
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		labelTitle->Draw();
	glColor4f(0.0f, 0.2f, 0.4f, 0.8f);
	panelDescription->Draw();
	glColor4f(0.0f, 0.2f, 0.4f, 0.8f);
	panelStat->Draw();

	glColor4f(0.2f, 0.4f, 0.6f, 0.8f);
	buttonGo->Draw();
	HUD::End();
}

void ScreenChoice::Load()
{
	char* fontPath = "C:\\Windows\\Fonts\\tahoma.ttf";
	sphere = new HeightmapSphere();
	float horzSpacing = Settings::View::Width / 40.0f;
	float vertSpacing = Settings::View::Height / 40.0f;
	panelChoice = new Panel(
		6 * horzSpacing, 6 * vertSpacing,
		28 * horzSpacing, 10 * vertSpacing,
		20.0f);
	labelChoiceTitle = new Label(
		20 * horzSpacing, 7 * vertSpacing,
		"<STAGE NAME>", fontPath, true);
	buttonChoice1 = new Button(
		7 * horzSpacing, 8 * vertSpacing,
		5 * horzSpacing, 5 * vertSpacing,
		"<CHOICE 1>", fontPath);
	buttonChoice2 = new Button(
		14 * horzSpacing, 8 * vertSpacing,
		5 * horzSpacing, 5 * vertSpacing,
		"<CHOICE 2>", fontPath);
	buttonChoice3 = new Button(
		21 * horzSpacing, 8 * vertSpacing,
		5 * horzSpacing, 5 * vertSpacing,
		"<CHOICE 3>", fontPath);
	buttonChoice4 = new Button(
		28 * horzSpacing, 8 * vertSpacing,
		5 * horzSpacing, 5 * vertSpacing,
		"<CHOICE 4>", fontPath);
	panelTitle = new Panel(
		6 * horzSpacing, 18 * vertSpacing,
		28 * horzSpacing, 4 * vertSpacing,
		20.0f);
	labelTitle = new Label(
		20 * horzSpacing, 20 * vertSpacing,
		"<CHOICE TITLE>", fontPath, true);
	panelDescription = new Panel(
		6 * horzSpacing, 24 * vertSpacing,
		8 * horzSpacing, 10 * vertSpacing,
		20.0f);
	panelStat = new Panel(
		16 * horzSpacing, 24 * vertSpacing,
		8 * horzSpacing, 10 * vertSpacing,
		20.0f);
	buttonGo = new Button(
		26 * horzSpacing, 24 * vertSpacing,
		8 * horzSpacing, 10 * vertSpacing,
		"GO!", fontPath);
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