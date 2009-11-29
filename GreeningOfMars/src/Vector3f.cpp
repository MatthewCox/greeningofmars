#include "Vector3f.h"

Vector3f::Vector3f(void)
{
	m_X = 0;
	m_Y = 0;
	m_Z = 0;
}

Vector3f::Vector3f(float p_X, float p_Y, float p_Z)
{
	m_X = p_X;
	m_Y = p_Y;
	m_Z = p_Z;
}

Vector3f::~Vector3f(void)
{
}

float Vector3f::X() const
{
	return m_X;
}

float Vector3f::Y() const
{
	return m_Y;
}

float Vector3f::Z() const
{
	return m_Z;
}

Vector3f Vector3f::operator+(const Vector3f& v)
{
	return Vector3f(
		m_X + v.X(),
		m_Y + v.Y(),
		m_Z + v.Z()
		);
}

Vector3f Vector3f::operator-(const Vector3f& v)
{
	return Vector3f(
		m_X - v.X(),
		m_Y - v.Y(),
		m_Z - v.Z()
		);
}

float Vector3f::dot(const Vector3f& v) const
{
	return (m_X * v.X()) + (m_Y * v.Y()) + (m_Z * v.Z());
}

Vector3f Vector3f::cross(const Vector3f& v) const
{
	return Vector3f(
		(m_Y * v.Z()) - (m_Z * v.Y()),
		(m_Z * v.X()) - (m_X * v.Z()),
		(m_X * v.Y()) - (m_Y * v.X())
		);
}

Vector3f Vector3f::scaledBy(const float& scalar) const
{
	return Vector3f(
		(m_X * scalar),
		(m_Y * scalar),
		(m_Z * scalar)
		);
}

float Vector3f::length() const
{
	return sqrt((m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z));
}

Vector3f Vector3f::normalise() const
{
	return scaledBy(1 / length());
}