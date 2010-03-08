#include "MouseHandler.h"

bool MouseHandler::buttonState[3] = { false };
int MouseHandler::mouseX = 0;
int MouseHandler::mouseY = 0;

bool MouseHandler::previousButtonState[3] = { false };
int MouseHandler::previousMouseX = 0;
int MouseHandler::previousMouseY = 0;

MouseHandler::MouseHandler(void)
{

}

MouseHandler::~MouseHandler(void)
{
}

bool MouseHandler::Pressed(int button)
{
	return buttonState[button];
}

void MouseHandler::GetPosition(int &outX, int &outY)
{
	outX = mouseX;
	outY = mouseY;
}

void MouseHandler::SetState(int button, bool state)
{
	buttonState[button] = state;
}

void MouseHandler::SetPosition(int x, int y)
{
	mouseX = x;
	mouseY = y;
}