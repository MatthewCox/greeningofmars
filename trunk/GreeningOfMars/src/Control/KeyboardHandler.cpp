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

bool KeyboardHandler::Held(const unsigned char& key)
{
	return keyState[key];
}
bool KeyboardHandler::Pressed(const unsigned char& key)
{
	return (Held(key) && !oldKeyState[key]);
}
bool KeyboardHandler::Released(const unsigned char& key)
{
	return (!Held(key) && oldKeyState[key]);
}

bool KeyboardHandler::SpecialHeld(const int& key)
{
	return specialKeyState[key];
}
bool KeyboardHandler::SpecialPressed(const int& key)
{
	return (specialKeyState[key] == true && oldSpecialKeyState[key] == false);
}
bool KeyboardHandler::SpecialReleased(const int& key)
{
	return (specialKeyState[key] == false && oldSpecialKeyState[key] == true);
}

void KeyboardHandler::KeyDown(const unsigned char& key, const int& x, const int& y)
{
#ifdef OUTPUT_KEYCODES
	std::cout << "Norm: " << key << " (" << (int)key << ")" << std::endl;
#endif
	keyState[key] = true;
}
void KeyboardHandler::KeyUp(const unsigned char& key, const int& x, const int& y)
{
	keyState[key] = false;
}

void KeyboardHandler::SpecialKeyDown(const int& key, const int& x, const int& y)
{
#ifdef OUTPUT_KEYCODES
	std::cout << "Spec: " << key << std::endl;
#endif
	specialKeyState[key] = true;
}
void KeyboardHandler::SpecialKeyUp(const int& key, const int& x, const int& y)
{
	specialKeyState[key] = false;
}