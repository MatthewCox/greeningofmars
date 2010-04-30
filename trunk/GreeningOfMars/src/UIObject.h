#pragma once

#include "DrawableObject.h"

#include "Vector2f.h"

class UIObject : public DrawableObject
{
public:
	UIObject(void);
	~UIObject(void);

protected:
	Vector2f position;
};
