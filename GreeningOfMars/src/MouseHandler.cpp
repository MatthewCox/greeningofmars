#include "MouseHandler.h"

bool MouseHandler::buttonState[5] = { false };
int MouseHandler::mouseX = 0;
int MouseHandler::mouseY = 0;

bool MouseHandler::oldButtonState[5] = { false };
int MouseHandler::oldMouseX = 0;
int MouseHandler::oldMouseY = 0;

void MouseHandler::Update()
{
	for (int i = 0; i < 5; ++i)
	{
		oldButtonState[i] = buttonState[i];
	}
	oldMouseX = mouseX;
	oldMouseY = mouseY;
}

bool MouseHandler::Held(int button)
{
	return buttonState[button];
}
bool MouseHandler::Pressed(int button)
{
	return (Held(button) && !oldButtonState[button]);
}
bool MouseHandler::Released(int button)
{
	return (!Held(button) && oldButtonState[button]);
}
void MouseHandler::GetPosition(int &outX, int &outY)
{
	outX = mouseX;
	outY = mouseY;
}

void MouseHandler::SetState(int button, int state)
{
	if (state == 0)
	{
		buttonState[button] = true;
	}
	else
	{
		buttonState[button] = false;
	}
}

void MouseHandler::SetPosition(int x, int y)
{
	mouseX = x;
	mouseY = y;
}