#pragma once

#include "../Maths/Vector3f.h"

class Camera
{
private:
	Vector3f position, viewDir;
	float rotationX, rotationY;
	int lastX, lastY;

public:
	Camera(void);
	Camera(Vector3f p_position, float p_rotationX, float p_rotationY);
	Camera(Vector3f p_position, Vector3f p_viewDir, float p_rotationX, float p_rotationY);
	~Camera(void);

	Vector3f Position();
	float RotationX();
	float RotationY();

	void Position(Vector3f p_position);
	void RotationX(float p_rotationX);

	void Display();

	void MoveForwards(float p_moveSpeed);
	void MoveBackwards(float p_moveSpeed);
	void MoveLeft(float p_moveSpeed);
	void MoveRight(float p_moveSpeed);
	void RotateUp(float p_rotateSpeed);
	void RotateDown(float p_rotateSpeed);
	void RotateLeft(float p_rotateSpeed);
	void RotateRight(float p_rotateSpeed);

	void MouseLook(int p_x, int p_y, float p_movementRatio);
};
