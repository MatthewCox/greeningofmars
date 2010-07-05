#include "Vector3f.h"

#include <math.h>

Vector3f::Vector3f(void)
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3f::Vector3f(float p_xyz)
{
	x = p_xyz;
	y = p_xyz;
	z = p_xyz;
}

Vector3f::Vector3f(float p_x, float p_y, float p_z)
{
    x = p_x;
    y = p_y;
    z = p_z;
}

Vector3f::~Vector3f(void)
{
}

float Vector3f::X(void) const
{
    return x;
}

float Vector3f::Y(void) const
{
    return y;
}

float Vector3f::Z(void) const
{
    return z;
}

bool Vector3f::operator==(const Vector3f& p_v) const
{
    return (x == p_v.X() && y == p_v.Y() && z == p_v.Z());
}

bool Vector3f::operator!=(const Vector3f& p_v) const
{
    return !(*this == p_v);
}

Vector3f Vector3f::operator-() const
{
    return Vector3f(-x, -y, -z);
}

Vector3f Vector3f::operator+(const Vector3f& p_v) const
{
    Vector3f temp = Vector3f(x, y, z);
    temp += p_v;
    return temp;
}

Vector3f Vector3f::operator-(const Vector3f& p_v) const
{
    Vector3f temp = Vector3f(x, y, z);
    temp -= p_v;
    return temp;
}

Vector3f& Vector3f::operator+=(const Vector3f& p_v)
{
    x += p_v.X();
    y += p_v.Y();
    z += p_v.Z();
    return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f& p_v)
{
    x -= p_v.X();
    y -= p_v.Y();
    z -= p_v.Z();
    return *this;
}

float Vector3f::dot(const Vector3f& p_v) const
{
    return (x * p_v.X()) + (y * p_v.Y()) + (z * p_v.Z());
}

Vector3f Vector3f::cross(const Vector3f& p_v) const
{
    return Vector3f(
        (y * p_v.Z()) - (z * p_v.Y()),
        (z * p_v.X()) - (x * p_v.Z()),
        (x * p_v.Y()) - (y * p_v.X())
    );
}

float Vector3f::length(void) const
{
    return sqrt((x * x) + (y * y) + (z * z));
}

float Vector3f::length2(void) const
{
    return (x * x) + (y * y) + (z * z);
}

Vector3f Vector3f::normalize(void) const
{
    return *this * (1 / length());
}
