#pragma once

#include "../Game Components/DrawableObject.h"

#include "../Maths/Vector2f.h"
#include "../Graphics/ColourA.h"

class UIObject : public DrawableObject
{
public:
	UIObject(void);
	~UIObject(void);

	virtual void Update(float f_dt) = 0;

	void SetPosition(Vector2f p_position);
	void SetColour(ColourA p_colour);

protected:
	Vector2f position;
	ColourA colour;
};
