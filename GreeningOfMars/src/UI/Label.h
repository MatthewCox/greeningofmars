#pragma once

#include "UIObject.h"

#include "../Maths/Vector2f.h"
#include "../Graphics/ColourA.h"

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

	char* Name() const;
	void Name(char* p_name);

protected:
	char* name;
	bool center;
	FTPolygonFont* font;
};
