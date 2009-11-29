#pragma once

class DrawableObject
{
public:
	DrawableObject(void);
	~DrawableObject(void);

	virtual void Draw(void) = 0;
};
