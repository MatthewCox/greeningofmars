#pragma once

class MouseHandler
{
private:
	static bool buttonState[3];
	static int mouseX;
	static int mouseY;

	static bool previousButtonState[3];
	static int previousMouseX;
	static int previousMouseY;
public:
	MouseHandler(void);
	~MouseHandler(void);

	static bool Pressed(int button);
	static void GetPosition(int& outX, int& outY);
	static void SetState(int button, bool state);
	static void SetPosition(int x, int y);
};