#include "Camera.h"

#include <stdlib.h>
#include <math.h>

#include <GL/freeglut.h>

#include "../Maths/Vector3f.h"

Camera::Camera(void)
{
	position = Vector3f(0.f);
	viewDir = Vector3f(0.f);
	rotationX = 0;
	rotationY = 0;
	lastX = -1;
	lastY = -1;
}
Camera::Camera(Vector3f p_position, float p_rotationX, float p_rotationY)
{
	position = p_position;
	viewDir = Vector3f(0.f);
	rotationX = p_rotationX;
	rotationY = p_rotationY;
	lastX = -1;
	lastY = -1;
}
Camera::Camera(Vector3f p_position, Vector3f p_viewDir, float p_rotationX, float p_rotationY)
{
	position = p_position;
	viewDir = p_viewDir;
	rotationX = p_rotationX;
	rotationY = p_rotationY;
	lastX = -1;
	lastY = -1;
}

Camera::~Camera(void)
{
}

Vector3f Camera::Position()
{
	return position;
}

float Camera::RotationX()
{
	return rotationX;
}

float Camera::RotationY()
{
	return rotationY;
}

void Camera::Position(Vector3f p_position)
{
	position = p_position;
}

void Camera::RotationX(float p_rotationX)
{
	rotationX = p_rotationX;
}

void Camera::Display()
{
	glRotatef(
		rotationX,
		1.0,
		0.0,
		0.0
	); //rotate our camera on the x-axis (up and down)
	glRotatef(
		rotationY,
		0.0,
		1.0,
		0.0
	); //rotate our camera on the y-axis (left and right)
	glTranslatef(
		-position.X(),
		-position.Y(),
		-position.Z()
	); //translate the screen to the position of our camera
}

void Camera::MoveForwards(float p_moveSpeed)
{
//	position -= viewDir * p_moveSpeed;
 	float yrotrad = ((rotationY / 180) * 3.141592654f);
 	float xrotrad = ((rotationX / 180) * 3.141592654f);
 	position = Vector3f(
 		position.X() + (float(sin(yrotrad)) * p_moveSpeed),
 		position.Y() - (float(sin(xrotrad)) * p_moveSpeed),
 		position.Z() - (float(cos(yrotrad)) * p_moveSpeed)
 	);
}

void Camera::MoveBackwards(float p_moveSpeed)
{
	MoveForwards(-p_moveSpeed);
}

void Camera::MoveLeft(float p_moveSpeed)
{
	float yrotrad = ((rotationY / 180) * 3.141592654f);
	position = Vector3f(
		position.X() - (float(cos(yrotrad)) * p_moveSpeed),
		position.Y(),
		position.Z() - (float(sin(yrotrad)) * p_moveSpeed)
	);
}

void Camera::MoveRight(float p_moveSpeed)
{
	MoveLeft(-p_moveSpeed);
}

void Camera::RotateUp(float p_rotateSpeed)
{
	rotationX -= p_rotateSpeed;
	if (rotationX < 0)
	{
		rotationX += 360;
	}
}

void Camera::RotateDown(float p_rotateSpeed)
{
	rotationX += p_rotateSpeed;
	if (rotationX >= 360)
	{
		rotationX -= 360;
	}
}

void Camera::RotateLeft(float p_rotateSpeed)
{
	rotationY -= p_rotateSpeed;
	if (rotationY < 0)
	{
		rotationY += 360;
	}
}

void Camera::RotateRight(float p_rotateSpeed)
{
	rotationY += p_rotateSpeed;
	if (rotationY >= 360)
	{
		rotationY -= 360;
	}
}

void Camera::MouseLook(int p_x, int p_y, float p_movementRatio)
{
	if (lastX < 0 && lastY < 0)
	{
		lastX = p_x;
		lastY = p_y;
	}

	float dx = (float)(p_x - lastX) * p_movementRatio;
	float dy = (float)(p_y - lastY) * p_movementRatio;

	lastX = p_x;
	lastY = p_y;

	if (dx == 0.f && dy == 0.f)
	{
		return;
	}

	/*viewDir = Vector3f(
		viewDir.Z() * sin(dx) + viewDir.X() * cos(dx),
		viewDir.Y(),
		viewDir.Z() * cos(dx) - viewDir.X() * sin(dx));
	viewDir = Vector3f(
		viewDir.X(),
		viewDir.Y() * cos(dy) - viewDir.Z() * sin(dy),
		viewDir.Y() * sin(dy) + viewDir.Z() * cos(dy));*/

	int windowLeft = 0;
	int windowTop = 0;
	int windowRight = glutGet(GLUT_WINDOW_WIDTH);
	int windowBottom = glutGet(GLUT_WINDOW_HEIGHT);

	lastX = windowRight/2;
	lastY = windowBottom/2;
	glutWarpPointer(lastX, lastY);

	rotationX += (float)dy;
	rotationY += (float)dx;

	if (rotationX > 90)
	{
		rotationX = 90;
	}
	else if (rotationX < -90)
	{
		rotationX = -90;
	}
}