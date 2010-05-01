#pragma once

#include "DrawableObject.h"

#include "Vector2f.h"

class UIObject : public DrawableObject
{
public:
	UIObject(void);
	~UIObject(void);

	void SetPosition(Vector2f p_position);

protected:
	Vector2f position;
};
