#pragma once

#include "UIObject.h"

#include "Vector2f.h"
#include "ColourA.h"

#include <FTGL/ftgl.h>

class Label : public UIObject
{
public:
	Label();
	Label(
		Vector2f p_position,
		char* p_name, char* p_fontPath,
		ColourA p_colour,
		bool p_center);
	~Label(void);

	virtual void Update(float f_dt);
	void Draw();

protected:
	char* name;
	bool center;
	FTPolygonFont* font;
};
