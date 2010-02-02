#pragma once

class Vector2f
{
private:
	float m_X, m_Y;

public:
	Vector2f(void);
	Vector2f(float p_X, float p_Y);

	~Vector2f(void);

	float X() const;
	float Y() const;

	Vector2f operator+(const Vector2f& p_V);
	Vector2f operator-(const Vector2f& p_V);

	float dot(const Vector2f& p_V) const;
	Vector2f scaledBy(const float& p_Scalar) const;
	float length() const;
	Vector2f normalise() const;
};
