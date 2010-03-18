#include "ScreenChoice.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include "Settings.h"
#include "HUD.h"

ScreenChoice::ScreenChoice(void)
{
}

ScreenChoice::~ScreenChoice(void)
{
}

void ScreenChoice::Update(float f_dt)
{

}

void ScreenChoice::Draw()
{
	glTranslatef(0.0f, 0.0f, -10.0f);
	sphere->Draw();

	HUD::Start(Settings::View::Width, Settings::View::Height);
	glColor4f(0.0f, 0.2f, 0.4f, 0.8f);
	panelChoice->Draw();
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
	sphere = new HeightmapSphere();
	float horzSpacing = Settings::View::Width / 20.0f;
	float vertSpacing = Settings::View::Height / 20.0f;
	panelChoice = new Panel(
		3 * horzSpacing, 3 * vertSpacing,
		14 * horzSpacing, 5 * vertSpacing,
		20.0f);
	panelTitle = new Panel(
		3 * horzSpacing, 9 * vertSpacing,
		14 * horzSpacing, 2 * vertSpacing,
		20.0f);
	labelTitle = new Label(
		10 * horzSpacing, 10 * vertSpacing,
		"<CHOICE TITLE>", "C:\\Windows\\Fonts\\tahoma.ttf", true);
	panelDescription = new Panel(
		3 * horzSpacing, 12 * vertSpacing,
		4 * horzSpacing, 5 * vertSpacing,
		20.0f);
	panelStat = new Panel(
		8 * horzSpacing, 12 * vertSpacing,
		4 * horzSpacing, 5 * vertSpacing,
		20.0f);
	buttonGo = new Button(
		13 * horzSpacing, 12 * vertSpacing,
		4 * horzSpacing, 5 * vertSpacing,
		"GO!", "C:\\Windows\\Fonts\\tahoma.ttf");
}

void ScreenChoice::Unload()
{
	delete sphere;
	delete panelChoice;
	delete panelTitle;
	delete labelTitle;
	delete panelDescription;
	delete panelStat;
	delete buttonGo;
}