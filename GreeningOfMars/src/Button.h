#pragma once

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut.h>

#include <FTGL/ftgl.h>

#include "DrawableObject.h"

class Button : public DrawableObject
{
public:
	Button();
	Button(float p_x, float p_y,
		float p_width, float p_height,
		char* p_name, char* p_fontPath);
	~Button(void);

	void Draw(void);
	bool CheckClicked(const int &p_x, const int &p_y, const int p_button, const int p_state) const;

protected:
	float x, y, width, height;
	char* name;
};
