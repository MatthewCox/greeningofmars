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

	// Comparison
	bool operator==(const Vector2f& p_v) const;
	bool operator!=(const Vector2f& p_v) const;
	// Unary
	Vector2f operator-() const;
	// Scalar
	template <typename T> Vector2f operator*(const T& p_scalar) const
	{
		Vector2f temp = Vector2f(x, y);
		temp *= p_scalar;
		return temp;
	}
	// Arithmetic
	Vector2f operator+(const Vector2f& p_v) const;
	Vector2f operator-(const Vector2f& p_v) const;
	// Shorthand
	Vector2f& operator+=(const Vector2f& p_v);
	Vector2f& operator-=(const Vector2f& p_v);
	template <typename T> Vector2f& operator*=(const T& p_scalar)
	{
		x *= p_scalar;
		y *= p_scalar;
		return *this;
	};

	float dot(const Vector2f& p_v) const;
	float length(void) const;
	float length2(void) const;
	Vector2f normalise(void) const;
};
