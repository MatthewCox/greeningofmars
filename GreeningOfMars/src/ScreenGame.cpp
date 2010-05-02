#include "ScreenGame.h"

#include <stdlib.h>
#include <iostream>

#include <GL/freeglut.h>

#include "Settings.h"
#include "KeyboardHandler.h"
#include "MouseHandler.h"

#include "MousePick.h"

ScreenGame::ScreenGame(void)
{
}

ScreenGame::~ScreenGame(void)
{
}

void ScreenGame::Update(float f_dt)
{
	mars->Update(f_dt);

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
	if (MouseHandler::Pressed(0))
	{
		camera->MouseLook(mouseX, mouseY, Settings::Mouse::MovementRatio * f_dt);
	}
	mouseY = Settings::View::Height - mouseY;
	if (MouseHandler::Pressed(2))
	{
		Vector3f mouseRay = MousePick::MouseRay(mouseX, mouseY, startPoint, endPoint);
		mouseRay = mouseRay.normalize();

		float A, B, C, t1, t2, discriminant;
		A = mouseRay.X()*mouseRay.X() +
			mouseRay.Y()*mouseRay.Y() +
			mouseRay.Z()*mouseRay.Z();
		B = 2.0f*(mouseRay.X() * startPoint.X() +
			mouseRay.Y() * startPoint.Y() +
			mouseRay.Z() * startPoint.Z());
		C = startPoint.X()*startPoint.X() +
			startPoint.Y()*startPoint.Y() +
			startPoint.Z()*startPoint.Z() - 5.0f*5.0f;
		discriminant = B*B - 4*(A*C);

		if (discriminant < 0.0f)
		{
			std::cout << "no intersect" << std::endl;
		}
		else if (discriminant == 0.0f)
		{
			std::cout << "tangent" << std::endl;
		}
		else
		{
			t1 = (-B + sqrt(discriminant)) * 0.5f*A;
			t2 = (-B - sqrt(discriminant)) * 0.5f*A;

			if (t1 > t2)
			{
				intersectionPoint = startPoint + mouseRay * t2;
			}
			else
			{
				intersectionPoint = startPoint + mouseRay * t1;
			}

			std::cout << "t1: " << t1 << " t2: " << t2 << std::endl;
		}
	}
}

void ScreenGame::Draw()
{
	camera->Display();

	mars->Draw();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex3f(startPoint.X(), startPoint.Y(), startPoint.Z());
	glVertex3f(endPoint.X(), endPoint.Y(), endPoint.Z());
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex3f(intersectionPoint.X(),
		intersectionPoint.Y(),
		intersectionPoint.Z());
	glEnd();
}

void ScreenGame::Load()
{
	mars = new Mars();
	camera = new Camera(
		Vector3f(0.0f, 0.0f, 10.0f),
		0.0f, 0.0f);

	startPoint = Vector3f(0.0f);
	endPoint = Vector3f(0.0f);
	intersectionPoint = Vector3f(0.0f);
}

void ScreenGame::Unload()
{
	delete mars;
	delete camera;
}