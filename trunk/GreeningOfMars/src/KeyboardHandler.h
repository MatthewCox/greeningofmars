#pragma once

class KeyboardHandler
{
private:
	static bool keyState[256];
	static bool specialKeyState[256];
public:
	KeyboardHandler(void);
	~KeyboardHandler(void);

	static bool KeyState(unsigned char key);
	static bool SpecialKeyState(int key);

	static void KeyDown(unsigned char key);
	static void KeyUp(unsigned char key);

	static void SpecialKeyDown(int key);
	static void SpecialKeyUp(int key);
};