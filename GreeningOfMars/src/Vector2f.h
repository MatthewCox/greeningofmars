#pragma once

class Vector2f
{
private:
	float x, y;

public:
	Vector2f(void);
	Vector2f(float p_xy);
	Vector2f(float p_x, float p_y);

	~Vector2f(void);

	float X(void) const;
	float Y(void) const;

	Vector2f operator+(const Vector2f& p_v) const;
	Vector2f operator-(const Vector2f& p_v) const;
	Vector2f operator*(const float& p_scalar) const;

	float dot(const Vector2f& p_v) const;
	float length(void) const;
	float length2(void) const;
	Vector2f normalise(void) const;
};
