#pragma once

#include "DrawableObject.h"

#include "Vector2f.h"

#include <FTGL\ftgl.h>

class Label : public DrawableObject
{
public:
	Label();
	Label(
		Vector2f p_position,
		char* p_name, char* p_fontPath,
		bool p_center);
	~Label(void);

	virtual void Update(float f_dt);
	void Draw();

protected:
	Vector2f position;
	char* name;
	bool center;
	FTPolygonFont* font;
};
