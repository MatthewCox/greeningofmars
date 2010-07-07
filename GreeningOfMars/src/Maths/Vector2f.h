#pragma once
/****************************************************************************
* 																			*
* Vector2f																	*
* 																			*
* Implements 2D vectors, and common operations that can be					*
* performed with them.														*
* 																			*
* Written by Matthew Cox, 2008-2010											*
* 																			*
****************************************************************************/
class Vector2f
{
private:
	float x, y;

public:
	// Default constructor, initializes x and y to 0
	Vector2f(void);
	// Single-value constructor, initializes x and y to the same value
	Vector2f(float p_xy);
	// Full constructor, initializes x and y to the specified values
	Vector2f(float p_x, float p_y);

	// Destructor
	~Vector2f(void);

	// Returns the vector's x value
	float X(void) const;
	// Returns the vector's y value
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

	// Returns the dot product of this and the specified vector
	float dot(const Vector2f& p_v) const;
	// Returns the scalar length of the vector (uses sqrt(), if possible it is better to use length2)
	float length(void) const;
	// Returns the squared length of the vector
	float length2(void) const;
	// Returns a normalized copy of the vector
	Vector2f normalize(void) const;
};
