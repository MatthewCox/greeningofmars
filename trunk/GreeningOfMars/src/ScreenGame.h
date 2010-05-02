#pragma once

#include "Screen.h"

#include "Camera.h"
#include "Mars.h"

class ScreenGame : public Screen
{
public:
	ScreenGame(void);
	~ScreenGame(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Camera *camera;
	Mars *mars;

	Vector3f startPoint, endPoint, intersectionPoint;
};
