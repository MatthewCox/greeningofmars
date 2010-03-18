#pragma once

#include "DrawableObject.h"

class Panel : public DrawableObject
{
public:
	Panel();
	Panel(float p_x, float p_y,
		float p_width, float p_height,
		float p_cornerInset);
	~Panel(void);

	virtual void Update(float f_dt);
	void Draw(void);

protected:
	float x, y, width, height, cornerInset;
};
