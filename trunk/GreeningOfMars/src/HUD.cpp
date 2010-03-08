#include "HUD.h"

#include <stdlib.h>

#include <GL\freeglut.h>

HUD::HUD(void)
{
}

HUD::~HUD(void)
{
}

void HUD::Start(int p_width, int p_height)
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
		gluOrtho2D(0, p_width, 0, p_height);
		glDisable(GL_DEPTH_TEST);
		glDepthMask(GL_FALSE);
		glScalef(1, -1, 1);
		glTranslatef(0, (float)-p_height, 0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
}
void HUD::End()
{
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
}