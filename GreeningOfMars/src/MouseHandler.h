#pragma once

class MouseHandler
{
public:
	static void Update();

	static bool Held(int button);
	static bool Pressed(int button);
	static bool Released(int button);
	static void GetPosition(int& outX, int& outY);

	static void SetState(int button, int state);
	static void SetPosition(int x, int y);

private:
	static bool buttonState[5];
	static int mouseX;
	static int mouseY;

	static bool oldButtonState[5];
	static int oldMouseX;
	static int oldMouseY;
};