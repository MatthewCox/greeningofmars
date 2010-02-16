#include "Button.h"

#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/freeglut.h>

#include <FTGL/ftgl.h>

Button::Button(void)
{
	x = 0;
	y = 0;
	width = 200;
	height = 50;
	name = "<button>";
}

Button::Button(float p_x, float p_y,
			   float p_width, float p_height,
			   char* p_name, char* p_fontPath)
{
	x = p_x;
	y = p_y;
	width = p_width;
	height = p_height;
	name = p_name;
}

Button::~Button(void)
{
}

void Button::Draw()
{
	glBegin(GL_QUADS);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glVertex2f(x, y);
	glVertex2f(x, y + height);
	glVertex2f(x + width, y + height);
	glVertex2f(x + width, y);
	glEnd();

	FTPixmapFont font("C:\\Windows\\Fonts\\tahoma.ttf");
	font.FaceSize(24);
	float strWidth = font.BBox(name).Upper().Xf() - font.BBox(name).Lower().Xf();
	float strHeight = font.BBox(name).Upper().Yf() - font.BBox(name).Lower().Yf();
	glRasterPos2f(
		x + ((width / 2) - (strWidth / 2)),
		y + (height / 2) + (strHeight / 2)
		);
	font.Render(name);
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