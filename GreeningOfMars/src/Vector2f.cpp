#include "Vector2f.h"

#include <math.h>

Vector2f::Vector2f(void)
{
    x = 0;
    y = 0;
}

Vector2f::Vector2f(float p_xy)
{
	x = p_xy;
	y = p_xy;
}

Vector2f::Vector2f(float p_x, float p_y)
{
    x = p_x;
    y = p_y;
}

Vector2f::~Vector2f(void)
{
}

float Vector2f::X(void) const
{
    return x;
}

float Vector2f::Y(void) const
{
    return y;
}

bool Vector2f::operator==(const Vector2f& p_v) const
{
	return (x == p_v.X() && y == p_v.Y());
}

bool Vector2f::operator!=(const Vector2f& p_v) const
{
	return !(*this == p_v);
}

Vector2f Vector2f::operator-() const
{
	return Vector2f(-x, -y);
}

Vector2f Vector2f::operator+(const Vector2f& p_v) const
{
	Vector2f temp = Vector2f(x, y);
	temp += p_v;
	return temp;
}

Vector2f Vector2f::operator-(const Vector2f& p_v) const
{
	Vector2f temp = Vector2f(x, y);
	temp -= p_v;
	return temp;
}

Vector2f& Vector2f::operator+=(const Vector2f& p_v)
{
	x += p_v.X();
	y += p_v.Y();
	return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& p_v)
{
	x -= p_v.X();
	y -= p_v.Y();
	return *this;
}

float Vector2f::dot(const Vector2f& p_v) const
{
    return (x * p_v.X()) + (y * p_v.Y());
}

float Vector2f::length(void) const
{
    return sqrt((x * x) + (y * y));
}

float Vector2f::length2(void) const
{
    return (x * x) + (y * y);
}

Vector2f Vector2f::normalise(void) const
{
    return *this * (1 / length());
}
