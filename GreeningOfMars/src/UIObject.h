#pragma once

#include "DrawableObject.h"

#include "Vector2f.h"
#include "ColourA.h"

class UIObject : public DrawableObject
{
public:
	UIObject(void);
	~UIObject(void);

	void SetPosition(Vector2f p_position);
	void SetColour(ColourA p_colour);

protected:
	Vector2f position;
	ColourA colour;
};
