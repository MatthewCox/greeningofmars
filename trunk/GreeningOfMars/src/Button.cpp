#include "Button.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include <FTGL\ftgl.h>

Button::Button(void)
{
}

Button::Button(float p_x, float p_y,
			   float p_width, float p_height,
			   char* p_name, char* p_fontPath) : Panel(p_x, p_y, p_width, p_height, 20.0f)
{
	label = new Label(
		p_x + (p_width / 2), p_y + (p_height / 2),
		p_name, p_fontPath,
		true);
}

Button::~Button(void)
{
	delete label;
}

void Button::Update(float f_dt)
{

}

void Button::Draw()
{
	Panel::Draw();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	label->Draw();
}

bool Button::CheckClicked(const int &p_x, const int &p_y) const
{
	if (p_x >= x && p_x <= x + width &&
		p_y >= y && p_y <= y + height)
	{
		return true;
	}
	return false;
}