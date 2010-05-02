#pragma once

#include <GL/freeglut.h>

#include "Vector2f.h"
#include "Vector3f.h"

class MousePick
{
public:
	MousePick();
	static Vector3f MouseRay(int p_mouseX, int p_mouseY,
		Vector3f &out_startPoint, Vector3f &out_endPoint);
};
