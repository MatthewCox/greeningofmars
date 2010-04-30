#include "Panel.h"

#include <stdlib.h>

#include <GL/freeglut.h>

Panel::Panel(void)
{
	position = Vector2f(0.0f, 0.0f);
	size = Vector2f(100.0f, 100.0f);
	cornerInset = 20.0f;
}

Panel::Panel(Vector2f p_position, Vector2f p_size, float p_cornerInset)
{
	position = p_position;
	size = p_size;
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
		glVertex2f(position.X(), position.Y() + cornerInset);
		glVertex2f(position.X(), position.Y() + size.Y());
		glVertex2f(position.X() + size.X() - cornerInset, position.Y() + size.Y());
		glVertex2f(position.X() + size.X(), position.Y() + size.Y() - cornerInset);
		glVertex2f(position.X() + size.X(), position.Y());
		glVertex2f(position.X() + cornerInset, position.Y());
	glEnd();
}