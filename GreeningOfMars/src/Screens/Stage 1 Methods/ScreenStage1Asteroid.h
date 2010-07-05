#pragma once

#include "../Screen.h"

#include "../../Game Components/Camera.h"
#include "../../Game Components/Mars.h"
#include "../../Game Components/Asteroid.h"
#include "../../Maths/Vector3f.h"
#include "../../UI/SwishyButton.h"

class ScreenStage1Asteroid : public CScreen
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
