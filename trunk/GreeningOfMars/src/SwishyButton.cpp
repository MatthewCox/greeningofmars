#include "SwishyButton.h"

SwishyButton::SwishyButton(void)
{
	swishDir = 0;
}
SwishyButton::SwishyButton(float p_x, float p_y,
						   float p_width, float p_height,
						   char *p_name, char *p_fontPath,
						   int p_swishDir) : Button(
						   p_x, p_y,
						   p_width, p_height,
						   p_name, p_fontPath)
{
	swishDir = p_swishDir;
	targetX = x;
	targetY = y;

	switch (swishDir)
	{
	case 0:
		x = -width;
		break;
	case 1:
		x = (float)glutGet(GLUT_WINDOW_WIDTH);
		break;
	case 2:
		y = -height;
		break;
	case 3:
		y = (float)glutGet(GLUT_WINDOW_HEIGHT);
		break;
	}
}

SwishyButton::~SwishyButton(void)
{
}

void SwishyButton::Update(float f_dt)
{
	switch (swishDir)
	{
	case 0:
		if (x < targetX)
		{
			x += 100 * f_dt;
		}
		break;
	case 1:
		if (x > targetX)
		{
			x -= 100 * f_dt;
		}
		break;
	case 2:
		if (y < targetY)
		{
			y += 100 * f_dt;
		}
		break;
	case 3:
		if (y > targetY)
		{
			y -= 100 * f_dt;
		}
		break;
	}
}