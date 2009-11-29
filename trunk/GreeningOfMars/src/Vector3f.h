#pragma once

#include <math.h>

class Vector3f
{
private:
	float m_X, m_Y, m_Z;

public:
	Vector3f(void);
	Vector3f(float p_X, float p_Y, float p_Z);

	~Vector3f(void);

	float X() const;
	float Y() const;
	float Z() const;

	Vector3f operator+(const Vector3f& p_V);
	Vector3f operator-(const Vector3f& p_V);

	float dot(const Vector3f& p_V) const;
	Vector3f cross(const Vector3f& p_V) const;
	Vector3f scaledBy(const float& p_Scalar) const;
	float length() const;
	Vector3f normalise() const;
};