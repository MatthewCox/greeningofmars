#pragma once

#include <math.h>
#include <windows.h>

#include <GL/gl.h>
#include <GL/freeglut.h>

#include "Vector3f.h"

class Camera
{
private:
	Vector3f m_position;
	float m_rotationX, m_rotationY;
	int m_lastX, m_lastY;

public:
	Camera(void);
	Camera(Vector3f p_position, float p_rotationX, float p_rotationY);
	~Camera(void);

	Vector3f Position();
	float RotationX();
	float RotationY();

	void Position(Vector3f p_position);
	void RotationX(float p_rotationX);

	void Display();

	void MoveForwards(float p_move_speed);
	void MoveBackwards(float p_move_speed);
	void MoveLeft(float p_move_speed);
	void MoveRight(float p_move_speed);
	void RotateUp(float p_rotate_speed);
	void RotateDown(float p_rotate_speed);
	void RotateLeft(float p_rotate_speed);
	void RotateRight(float p_rotate_speed);

	void MouseLook(int p_x, int p_y, float p_movement_ratio);
};
