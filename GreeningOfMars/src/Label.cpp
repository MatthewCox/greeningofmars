#include "Label.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include <FTGL\ftgl.h>

Label::Label(void)
{
	position = Vector2f(0.0f, 0.0f);
	name = "<label>";
	center = false;
	font = new FTPolygonFont("C:\\Windows\\Fonts\\tahoma.ttf");
	font->FaceSize(24);
}

Label::Label(Vector2f p_position,
			 char* p_name, char* p_fontPath,
			 bool p_center)
{
	position = p_position;
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
			position.X() - (strWidth / 2),
			position.Y() + (strHeight / 2),
			0.0f);
	} 
	else
	{
		glTranslatef(position.X(), position.Y(), 0.0f);
	}
	glScalef(1.0f, -1.0f, 1.0f);
	font->Render(name);
	glPopMatrix();
}