#pragma once

#include "DrawableObject.h"

#include "Vector3f.h"

class GameObject : public DrawableObject
{
public:
	GameObject(void);
	~GameObject(void);

	virtual void Update(float f_dt) = 0;
	virtual void Draw(void) = 0;

protected:
	Vector3f position;
};
