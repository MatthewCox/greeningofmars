#pragma once

#include "../Maths/Vector3f.h"

class MousePick
{
public:
	static Vector3f MouseRay(int p_mouseX, int p_mouseY,
		Vector3f &out_startPoint);
};
