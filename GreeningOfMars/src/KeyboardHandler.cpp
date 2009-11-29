#include "KeyboardHandler.h"

bool KeyboardHandler::keyState[256] = { false };
bool KeyboardHandler::specialKeyState[256] = { false };

KeyboardHandler::KeyboardHandler(void)
{

}

KeyboardHandler::~KeyboardHandler(void)
{
}

bool KeyboardHandler::KeyState(unsigned char key)
{
	return keyState[key];
}
void KeyboardHandler::KeyDown(unsigned char key)
{
	keyState[key] = true;
}
void KeyboardHandler::KeyUp(unsigned char key)
{
	keyState[key] = false;
}

bool KeyboardHandler::SpecialKeyState(int key)
{
	return specialKeyState[key];
}
void KeyboardHandler::SpecialKeyDown(int key)
{
	specialKeyState[key] = true;
}
void KeyboardHandler::SpecialKeyUp(int key)
{
	specialKeyState[key] = false;
}