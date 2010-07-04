#include "ScreenStage1Asteroid.h"

#include <GL/freeglut.h>

#include "Camera.h"
#include "Mars.h"
#include "Asteroid.h"
#include "Vector3f.h"
#include "SwishyButton.h"

#include "HUD.h"
#include "Settings.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"
#include "Screens.h"

#include "MousePick.h"
#include "Intersect.h"

ScreenStage1Asteroid::ScreenStage1Asteroid(void)
{
}

ScreenStage1Asteroid::~ScreenStage1Asteroid(void)
{
}

void ScreenStage1Asteroid::Update(float f_dt)
{
	mars->Update(f_dt);

	int mouseX, mouseY;
	MouseHandler::GetPosition(mouseX, mouseY);
	mouseY = Settings::View::Height - mouseY;
	if (!asteroid->Finished() && MouseHandler::Held(0))
	{
		Vector3f startPoint;
		Vector3f mouseRay = MousePick::MouseRay(
			mouseX, mouseY,
			startPoint);
		mouseRay = mouseRay.normalize();

		bool intersect;
		intersectionPoint = Intersect::RaySphere(
			startPoint, mouseRay,
			mars->Position(), mars->Sphere()->Radius(),
			intersect);
		if (intersect == true)
		{
			asteroid->Position(intersectionPoint.normalize() * 10.0f);
			asteroid->Velocity(-intersectionPoint.normalize() * 3.0f);
		}
	}

	MouseHandler::GetPosition(mouseX, mouseY);
	if (asteroid->Position() != Vector3f(0.0f))
	{
		asteroid->Update(f_dt);
	}
	else if (intersectionPoint != Vector3f(0.0f))
	{
		buttonNextStage->Update(f_dt);

		if (MouseHandler::Released(0) && buttonNextStage->CheckClicked(mouseX, mouseY))
		{
			CScreenManager::GetInstance()->ChangeScreen(new ScreenChoiceWater());
		}
	}

	if (KeyboardHandler::Held('v'))
	{
		if (KeyboardHandler::Held('w'))
		{
			camera->MoveForwards(Settings::Movement::Speed * f_dt);
		}
		if (KeyboardHandler::Held('s'))
		{
			camera->MoveBackwards(Settings::Movement::Speed * f_dt);
		}
		if (KeyboardHandler::Held('a'))
		{
			camera->MoveLeft(Settings::Movement::Speed * f_dt);
		}
		if (KeyboardHandler::Held('d'))
		{
			camera->MoveRight(Settings::Movement::Speed * f_dt);
		}

		if (MouseHandler::Held(2))
		{
			camera->MouseLook(mouseX, mouseY, Settings::Mouse::MovementRatio * f_dt);
		}
	}
}

void ScreenStage1Asteroid::Draw()
{
	camera->Display();

	mars->Draw();

	asteroid->Draw();

	if (!asteroid->Finished())
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex3f(
			intersectionPoint.X(),
			intersectionPoint.Y(),
			intersectionPoint.Z());
		glVertex3f(
			intersectionPoint.X() * 2.0f,
			intersectionPoint.Y() * 2.0f,
			intersectionPoint.Z() * 2.0f);
		glEnd();
	}

	HUD::Start(Settings::View::Width, Settings::View::Height);
		buttonNextStage->Draw();
	HUD::End();
}

void ScreenStage1Asteroid::Load()
{
	camera = new Camera(
		Vector3f(0.0f, 0.0f, 15.0f),
		0.0f, 0.0f);

	mars = new Mars();

	asteroid = new Asteroid(Vector3f(0.0f), Vector3f(0.0f));
	asteroid->Radius(0.25f);

	intersectionPoint = Vector3f(0.0f);

	buttonNextStage = new SwishyButton(
		Vector2f(Settings::View::Width - 160.0f, Settings::View::Height - 40.0f),
		Vector2f(180.0f, 40.0f),
		"Next Stage",
		Settings::UI::FontPath,
		Settings::UI::ButtonColour,
		1);
	buttonNextStage->SwishOn();
}

void ScreenStage1Asteroid::Unload()
{
	delete mars;
	delete camera;
	delete asteroid;
	delete buttonNextStage;
}