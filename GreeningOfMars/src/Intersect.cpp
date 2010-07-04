#include "Intersect.h"

#include <math.h>

#include "Vector3f.h"

Vector3f Intersect::RaySphere(
		Vector3f p_rayOrigin, Vector3f p_rayUnitDir,
		Vector3f p_sphereCentre, float p_sphereRadius,
		bool &out_intersect)
{
	float A, B, C, t1, t2, discriminant;
	Vector3f rayMinusSphere = p_rayOrigin - p_sphereCentre;
	A = p_rayUnitDir.X()*p_rayUnitDir.X() +
		p_rayUnitDir.Y()*p_rayUnitDir.Y() +
		p_rayUnitDir.Z()*p_rayUnitDir.Z();
	B = 2.0f*(p_rayUnitDir.X() * rayMinusSphere.X() +
		p_rayUnitDir.Y() * rayMinusSphere.Y() +
		p_rayUnitDir.Z() * rayMinusSphere.Z());
	C = rayMinusSphere.X()*rayMinusSphere.X() +
		rayMinusSphere.Y()*rayMinusSphere.Y() +
		rayMinusSphere.Z()*rayMinusSphere.Z() -
		p_sphereRadius*p_sphereRadius;
	discriminant = B*B - 4*(A*C);

	if (discriminant >= 0.0f)
	{
		out_intersect = true;

		t1 = (-B + sqrt(discriminant)) * 0.5f*A;
		t2 = (-B - sqrt(discriminant)) * 0.5f*A;

		if (t1 > t2)
		{
			return p_rayOrigin + p_rayUnitDir * t2;
		}
		else
		{
			return p_rayOrigin + p_rayUnitDir * t1;
		}
	}

	out_intersect = false;
	return Vector3f(0.0f);
}