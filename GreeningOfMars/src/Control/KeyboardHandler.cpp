#include "KeyboardHandler.h"

#ifdef OUTPUT_KEYCODES
#include <iostream>
#endif

bool KeyboardHandler::keyState[256] = { false };
bool KeyboardHandler::specialKeyState[256] = { false };
bool KeyboardHandler::oldKeyState[256] = { false };
bool KeyboardHandler::oldSpecialKeyState[256] = { false };

void KeyboardHandler::Update()
{
	for (int i = 0; i < 256; ++i)
	{
		oldKeyState[i] = keyState[i];
		oldSpecialKeyState[i] = specialKeyState[i];
	}
}

bool KeyboardHandler::Held(unsigned char key)
{
	return keyState[key];
}
bool KeyboardHandler::Pressed(unsigned char key)
{
	return (Held(key) && !oldKeyState[key]);
}
bool KeyboardHandler::Released(unsigned char key)
{
	return (!Held(key) && oldKeyState[key]);
}

bool KeyboardHandler::SpecialHeld(int key)
{
	return specialKeyState[key];
}
bool KeyboardHandler::SpecialPressed(int key)
{
	return (specialKeyState[key] == true && oldSpecialKeyState[key] == false);
}
bool KeyboardHandler::SpecialReleased(int key)
{
	return (specialKeyState[key] == false && oldSpecialKeyState[key] == true);
}

void KeyboardHandler::KeyDown(unsigned char key)
{
#ifdef OUTPUT_KEYCODES
	std::cout << "Norm: " << key << std::endl;
#endif
	keyState[key] = true;
}
void KeyboardHandler::KeyUp(unsigned char key)
{
	keyState[key] = false;
}

void KeyboardHandler::SpecialKeyDown(int key)
{
#ifdef OUTPUT_KEYCODES
	std::cout << "Spec: " << key << std::endl;
#endif
	specialKeyState[key] = true;
}
void KeyboardHandler::SpecialKeyUp(int key)
{
	specialKeyState[key] = false;
}