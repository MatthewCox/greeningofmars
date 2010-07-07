#pragma once

/****************************************************************************
* 																			*
* MouseHandler																*
* 																			*
* Handles all things to do with mouse input, using glut's callback			*
* functions to keep the mouse's position and the state of each button		*
* updated. Handles up to 5 buttons, not sure of the maximum glut supports	*
* 																			*
* Written by Matthew Cox, 2009-2010											*
* 																			*
*****************************************************************************
* 																			*
* TODO: Handle the mousewheel. glutMouseWheelFunc() probably				*
* 																			*
****************************************************************************/
class MouseHandler
{
public:
	// Updates the state of each button, allowing Pressed and Released to work as intended
	static void Update();

	// Returns true if the specified button is currently held
	static bool Held(const int& button);
	// Returns true if the specified button was first pressed *this frame*
	static bool Pressed(const int& button);
	// Returns true if the specified button was held last frame, but not this frame
	static bool Released(const int& button);
	// Sets the input ints to the mouse's X and Y coordinates
	static void GetPosition(int& outX, int& outY);
	/*
	 * Sets the input ints to the x and y distance
	 * between the mouse's position this frame and it's previous position
	 */
	static void GetPositionChange(int& outDX, int& outDY);

	// Bind this to glutMouseFunc()
	static void Mouse(const int& button, const int& state, const int& x, const int& y);
	// Used by Mouse to set the state of each button
	static void SetState(const int& button, const int& state);
	// Bind this to glutMotionFunc() and glutPassiveMotionFunc()
	static void SetPosition(const int& x, const int& y);

private:
	static bool buttonState[5];
	static int mouseX;
	static int mouseY;

	static bool oldButtonState[5];
	static int oldMouseX;
	static int oldMouseY;
};