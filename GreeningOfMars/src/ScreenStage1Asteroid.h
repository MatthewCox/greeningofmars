#pragma once

#include "Screen.h"

#include "Camera.h"
#include "Mars.h"
#include "Asteroid.h"
#include "Vector3f.h"
#include "SwishyButton.h"

class ScreenStage1Asteroid : public Screen
{
public:
	ScreenStage1Asteroid(void);
	~ScreenStage1Asteroid(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();

private:
	Camera *camera;
	Mars *mars;
	Asteroid *asteroid;

	Vector3f intersectionPoint;

	SwishyButton *buttonNextStage;
};
