#include "Label.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include <FTGL\ftgl.h>

Label::Label(void)
{
	x = 0.0f;
	y = 0.0f;
	name = "<label>";
	center = false;
	font = new FTPolygonFont("C:\\Windows\\Fonts\\tahoma.ttf");
	font->FaceSize(24);
}

Label::Label(float p_x, float p_y,
			 char* p_name, char* p_fontPath,
			 bool p_center)
{
	x = p_x;
	y = p_y;
	name = p_name;
	center = p_center;
	font = new FTPolygonFont(p_fontPath);
	font->FaceSize(24);
}

Label::~Label(void)
{
	delete font;
}

void Label::Update(float f_dt)
{

}

void Label::Draw()
{
	glPushMatrix();
	if (center)
	{
		float strWidth = font->BBox(name).Upper().Xf() - font->BBox(name).Lower().Xf();
		float strHeight = font->BBox(name).Upper().Yf() - font->BBox(name).Lower().Yf();
		glTranslatef(
			x - (strWidth / 2),
			y + (strHeight / 2),
			0.0f);
	} 
	else
	{
		glTranslatef(x, y, 0.0f);
	}
	glScalef(1.0f, -1.0f, 1.0f);
	font->Render(name);
	glPopMatrix();
}