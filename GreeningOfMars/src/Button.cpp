#include "Button.h"

#include <stdlib.h>

#include <GL/freeglut.h>

#include <FTGL/ftgl.h>

Button::Button(void)
{
}

Button::Button(Vector2f p_position,
			   Vector2f p_size,
			   char* p_name, char* p_fontPath,
			   ColourA p_colour) : Panel(p_position, p_size, 20.0f, p_colour)
{
	label = new Label(
		Vector2f(p_position.X() + (p_size.X() / 2), p_position.Y() + (p_size.Y() / 2)),
		p_name, p_fontPath,
		ColourA(1.0f),
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
	label->Draw();
}

bool Button::CheckClicked(const int &p_x, const int &p_y) const
{
	if (p_x >= position.X() && p_x <= position.X() + size.X() &&
		p_y >= position.Y() && p_y <= position.Y() + size.Y())
	{
		return true;
	}
	return false;
}