#pragma once

// If defined, outputs key codes to console when keys are pressed
#define OUTPUT_KEYCODES

class KeyboardHandler
{
public:
	static void Update();

	static bool Held(unsigned char key);
	static bool Pressed(unsigned char key);
	static bool Released(unsigned char key);

	static bool SpecialHeld(int key);
	static bool SpecialPressed(int key);
	static bool SpecialReleased(int key);

	static void KeyDown(unsigned char key);
	static void KeyUp(unsigned char key);

	static void SpecialKeyDown(int key);
	static void SpecialKeyUp(int key);

private:
	static bool keyState[256];
	static bool oldKeyState[256];
	static bool specialKeyState[256];
	static bool oldSpecialKeyState[256];

};