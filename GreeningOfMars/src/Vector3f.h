#pragma once

class Vector3f
{
private:
	float x, y, z;

public:
	Vector3f(void);
	Vector3f(float p_xyz);
	Vector3f(float p_x, float p_y, float p_z);

	~Vector3f(void);

	float X(void) const;
	float Y(void) const;
	float Z(void) const;

	// Comparison
	bool operator==(const Vector3f& p_v) const;
	bool operator!=(const Vector3f& p_v) const;
    // Unary
    Vector3f operator-() const;
	// Scalar
	template <typename T> Vector3f operator*(const T& p_scalar) const
	{
	    Vector3f temp = Vector3f(x, y, z);
	    temp *= p_scalar;
	    return temp;
    };
    // Arithmetic
	Vector3f operator+(const Vector3f& p_v) const;
	Vector3f operator-(const Vector3f& p_v) const;
	// Shorthand
	Vector3f& operator+=(const Vector3f& p_v);
	Vector3f& operator-=(const Vector3f& p_v);
	template <typename T> Vector3f& operator*=(const T& p_scalar)
    {
        x *= p_scalar;
        y *= p_scalar;
        z *= p_scalar;
        return *this;
    };

	float dot(const Vector3f& p_v) const;
	Vector3f cross(const Vector3f& p_v) const;
	float length(void) const;
	float length2(void) const;
	Vector3f normalize(void) const;
};
