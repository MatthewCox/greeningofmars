#pragma once

#include "DrawableObject.h"

#include "Vector2f.h"

class Panel : public DrawableObject
{
public:
	Panel();
	Panel(Vector2f p_position, Vector2f p_size,
		float p_cornerInset);
	~Panel(void);

	virtual void Update(float f_dt);
	void Draw(void);

protected:
	Vector2f position, size;
	float cornerInset;
};
