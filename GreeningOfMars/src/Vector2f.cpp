#include "Vector2f.h"

#include <math.h>

Vector2f::Vector2f(void)
{
	m_X = 0;
	m_Y = 0;
}

Vector2f::Vector2f(float p_X, float p_Y)
{
	m_X = p_X;
	m_Y = p_Y;
}

Vector2f::~Vector2f(void)
{
}

float Vector2f::X() const
{
	return m_X;
}

float Vector2f::Y() const
{
	return m_Y;
}

Vector2f Vector2f::operator+(const Vector2f& v)
{
	return Vector2f(
		m_X + v.X(),
		m_Y + v.Y()
		);
}

Vector2f Vector2f::operator-(const Vector2f& v)
{
	return Vector2f(
		m_X - v.X(),
		m_Y - v.Y()
		);
}

float Vector2f::dot(const Vector2f& v) const
{
	return (m_X * v.X()) + (m_Y * v.Y());
}

Vector2f Vector2f::scaledBy(const float& scalar) const
{
	return Vector2f(
		(m_X * scalar),
		(m_Y * scalar)
		);
}

float Vector2f::length() const
{
	return sqrt((m_X * m_X) + (m_Y * m_Y));
}

Vector2f Vector2f::normalise() const
{
	return scaledBy(1 / length());
}