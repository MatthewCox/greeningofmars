#pragma once

#include "Vector3f.h"

class Intersect
{
public:

	static Vector3f RaySphere(
		Vector3f p_rayOrigin, Vector3f p_rayUnitDir,
		Vector3f p_sphereCentre, float p_sphereRadius,
		bool &out_intersect);
};
