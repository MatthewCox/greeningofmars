#pragma once

/* 
 * If defined, outputs key codes to console when keys are pressed.
 * Handy for finding out the codes for the keys you want to use.
 * Keycodes are output in the form 'Norm: KEY (KEYCODE)' and 'Spec: KEYCODE',
 * depending on the key. Norm tells you that you need the standard functions,
 * Spec means you need the Special-prefixed functions.
 */
#define OUTPUT_KEYCODES

/****************************************************************************
* 																			*
* KeyboardHandler															*
* 																			*
* Handles all things to do with keyboard input, using glut's callback		*
* functions to keep the state of each key updated							*
* 																			*
* Written by Matthew Cox, 2009-2010											*
* 																			*
*****************************************************************************
* 																			*
* TODO: A way to return the state of modifier keys (CTRL, SHIFT, ALT)		*
*        glutGetModifiers looks promising									*
* 																			*
****************************************************************************/
class KeyboardHandler
{
public:
	// Updates the state of each key, allowing Pressed and Released to work as intended
	static void Update();

	// Returns true if the specified key is currently held
	static bool Held(const unsigned char& key);
	// Returns true if the specified key was first pressed *this frame*
	static bool Pressed(const unsigned char& key);
	// Returns true if the specified key was held last frame, but not this frame
	static bool Released(const unsigned char& key);

	// Returns true if the specified key is currently held
	static bool SpecialHeld(const int& key);
	// Returns true if the specified key was first pressed *this frame*
	static bool SpecialPressed(const int& key);
	// Returns true if the specified key was held last frame, but not this frame
	static bool SpecialReleased(const int& key);

	/*
	 * In all of these, the mouse's x and y positions are ignored,
	 * but they need to be parameters to allow you to bind them
	 */
	// Bind this to glutKeyboardFunc()
	static void KeyDown(const unsigned char& key, const int& x, const int& y);
	// Bind this to glutKeyboardUpFunc()
	static void KeyUp(const unsigned char& key, const int& x, const int& y);

	// Bind this to glutSpecialFunc()
	static void SpecialKeyDown(const int& key, const int& x, const int& y);
	// Bind this to glutSpecialUpFunc()
	static void SpecialKeyUp(const int& key, const int& x, const int& y);

private:
	static bool keyState[256];
	static bool oldKeyState[256];
	static bool specialKeyState[256];
	static bool oldSpecialKeyState[256];

};