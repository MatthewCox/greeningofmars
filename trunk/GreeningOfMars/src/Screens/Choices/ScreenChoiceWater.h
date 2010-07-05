#pragma once

#include "ScreenChoice.h"

class ScreenChoiceWater : public ScreenChoice
{
public:
	ScreenChoiceWater(void);
	~ScreenChoiceWater(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();
};
