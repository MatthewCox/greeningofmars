#include "Camera.h"

Camera::Camera(void)
{
	m_position = Vector3f(0, 0, 0);
	m_rotationX = 0;
	m_rotationY = 0;
	m_lastX = -1;
	m_lastY = -1;
}

Camera::Camera(Vector3f p_position, float p_rotationX, float p_rotationY)
{
	m_position = p_position;
	m_rotationX = p_rotationX;
	m_rotationY = p_rotationY;
	m_lastX = -1;
	m_lastY = -1;
}

Camera::~Camera(void)
{
}

Vector3f Camera::Position()
{
	return m_position;
}

float Camera::RotationX()
{
	return m_rotationX;
}

float Camera::RotationY()
{
	return m_rotationY;
}

void Camera::Position(Vector3f p_position)
{
	m_position = p_position;
}

void Camera::RotationX(float p_rotationX)
{
	m_rotationX = p_rotationX;
}

void Camera::Display()
{
	glRotatef(
		m_rotationX,
		1.0,
		0.0,
		0.0
	); //rotate our camera on the x-axis (up and down)
	glRotatef(
		m_rotationY,
		0.0,
		1.0,
		0.0
	); //rotate our camera on the y-axis (left and right)
	glTranslatef(
		-m_position.X(),
		-m_position.Y(),
		-m_position.Z()
	); //translate the screen to the position of our camera
}

void Camera::MoveForwards(float p_move_speed)
{
	float yrotrad = (m_rotationY / 180 * 3.141592654f);
	float xrotrad = (m_rotationX / 180 * 3.141592654f);
	m_position = Vector3f(
		m_position.X() + (float(sin(yrotrad)) * p_move_speed),
		m_position.Y() - (float(sin(xrotrad)) * p_move_speed),
		m_position.Z() - (float(cos(yrotrad)) * p_move_speed)
	);
}

void Camera::MoveBackwards(float p_move_speed)
{
	float yrotrad = (m_rotationY / 180 * 3.141592654f);
	float xrotrad = (m_rotationX / 180 * 3.141592654f);
	m_position = Vector3f(
		m_position.X() - (float(sin(yrotrad)) * p_move_speed),
		m_position.Y() + (float(sin(xrotrad)) * p_move_speed),
		m_position.Z() + (float(cos(yrotrad)) * p_move_speed)
	);
}

void Camera::MoveLeft(float p_move_speed)
{
	float yrotrad = (m_rotationY / 180 * 3.141592654f);
	m_position = Vector3f(
		m_position.X() - (float(cos(yrotrad)) * p_move_speed),
		m_position.Y(),
		m_position.Z() - (float(sin(yrotrad)) * p_move_speed)
	);
}

void Camera::MoveRight(float p_move_speed)
{
	float yrotrad = (m_rotationY / 180 * 3.141592654f);
	m_position = Vector3f(
		m_position.X() + (float(cos(yrotrad)) * p_move_speed),
		m_position.Y(),
		m_position.Z() + (float(sin(yrotrad)) * p_move_speed)
	);
}

void Camera::RotateUp(float p_rotate_speed)
{
	m_rotationX -= p_rotate_speed;
	if (m_rotationX < -360)
	{
		m_rotationX += 360;
	}
}

void Camera::RotateDown(float p_rotate_speed)
{
	m_rotationX += p_rotate_speed;
	if (m_rotationX > 360)
	{
		m_rotationX -= 360;
	}
}

void Camera::RotateLeft(float p_rotate_speed)
{
	m_rotationY -= p_rotate_speed;
	if (m_rotationY < -360)
	{
		m_rotationY += 360;
	}
}

void Camera::RotateRight(float p_rotate_speed)
{
	m_rotationY += p_rotate_speed;
	if (m_rotationY > 360)
	{
		m_rotationY -= 360;
	}
}

void Camera::MouseLook(int p_x, int p_y, float p_movement_ratio)
{
	if (m_lastX < 0 && m_lastY < 0)
	{
		m_lastX = p_x;
		m_lastY = p_y;
	}

	int dx = p_x - m_lastX;
	int dy = p_y - m_lastY;

	m_lastX = p_x;
	m_lastY = p_y;

	if (dx == 0 && dy == 0)
	{
		return;
	}

	int windowLeft = 0;
	int windowTop = 0;
	int windowRight = glutGet(GLUT_WINDOW_WIDTH);
	int windowBottom = glutGet(GLUT_WINDOW_HEIGHT);

	//if (
	//	p_x <= windowLeft + 100 ||
	//	p_y <= windowTop + 100 ||
	//	p_x >= windowRight - 100 ||
	//	p_y >= windowBottom - 100
	//)
	//{
		m_lastX = windowRight/2;
		m_lastY = windowBottom/2;
		glutWarpPointer(m_lastX, m_lastY);
	//}

	m_rotationX += (float)dy * p_movement_ratio;
	m_rotationY += (float)dx * p_movement_ratio;

	if (m_rotationX > 90)
	{
		m_rotationX = 90;
	}
	else if (m_rotationX < -90)
	{
		m_rotationX = -90;
	}
}