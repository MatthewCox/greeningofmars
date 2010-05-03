#include "ScreenStage1Asteroid.h"

#include <stdlib.h>

#include <GL/freeglut.h>

#include "Camera.h"
#include "Mars.h"
#include "Asteroid.h"

#include "Settings.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"

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

	asteroid->Update(f_dt);

	if (KeyboardHandler::KeyState('w'))
	{
		camera->MoveForwards(Settings::Movement::Speed * f_dt);
	}
	if (KeyboardHandler::KeyState('s'))
	{
		camera->MoveBackwards(Settings::Movement::Speed * f_dt);
	}
	if (KeyboardHandler::KeyState('a'))
	{
		camera->MoveLeft(Settings::Movement::Speed * f_dt);
	}
	if (KeyboardHandler::KeyState('d'))
	{
		camera->MoveRight(Settings::Movement::Speed * f_dt);
	}

	int mouseX, mouseY;
	MouseHandler::GetPosition(mouseX, mouseY);
	if (MouseHandler::Pressed(2))
	{
		camera->MouseLook(mouseX, mouseY, Settings::Mouse::MovementRatio * f_dt);
	}
	mouseY = Settings::View::Height - mouseY;
	if (MouseHandler::Pressed(0))
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
}

void ScreenStage1Asteroid::Draw()
{
	camera->Display();

	mars->Draw();

	asteroid->Draw();

	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glVertex3f(intersectionPoint.X(),
		intersectionPoint.Y(),
		intersectionPoint.Z());
	glEnd();
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
}

void ScreenStage1Asteroid::Unload()
{
	delete mars;
	delete camera;
}