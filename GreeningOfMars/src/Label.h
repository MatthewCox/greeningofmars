#pragma once

#include "DrawableObject.h"

#include <FTGL\ftgl.h>

class Label : public DrawableObject
{
public:
	Label();
	Label(
		float p_x, float p_y,
		char* p_name, char* p_fontPath,
		bool p_center);
	~Label(void);

	virtual void Update(float f_dt);
	void Draw();

protected:
	float x, y;
	char* name;
	bool center;
	FTPolygonFont* font;
};
