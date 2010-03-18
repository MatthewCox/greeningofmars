#include "Panel.h"

#include <stdlib.h>

#include <GL\freeglut.h>

Panel::Panel(void)
{
	x = 0.0f;
	y = 0.0f;
	width = 100.0f;
	height = 100.0f;
	cornerInset = 20.0f;
}

Panel::Panel(float p_x, float p_y, float p_width, float p_height, float p_cornerInset)
{
	x = p_x;
	y = p_y;
	width = p_width;
	height = p_height;
	cornerInset = p_cornerInset;
}

Panel::~Panel(void)
{
}

void Panel::Update(float f_dt)
{
	
}

void Panel::Draw()
{
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y + cornerInset);
		glVertex2f(x, y + height);
		glVertex2f(x + width - cornerInset, y + height);
		glVertex2f(x + width, y + height - cornerInset);
		glVertex2f(x + width, y);
		glVertex2f(x + cornerInset, y);
	glEnd();
}