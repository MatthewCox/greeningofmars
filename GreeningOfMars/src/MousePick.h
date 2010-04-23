#pragma once

#include <GL/freeglut.h>

#include "Vector2f.h"
#include "Vector3f.h"

class MousePick
{
public:
	MousePick();
	static void Pick(int p_mouseX, int p_mouseY);
};
