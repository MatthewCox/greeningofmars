#pragma once

#include "ScreenChoice.h"

class ScreenChoiceHeat : public ScreenChoice
{
public:
	ScreenChoiceHeat(void);
	~ScreenChoiceHeat(void);

	void Update(float f_dt);
	void Draw();

	void Load();
	void Unload();
};
