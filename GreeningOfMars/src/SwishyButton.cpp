#include "SwishyButton.h"

#include <stdlib.h>

#include <GL\freeglut.h>

#include <FTGL\ftgl.h>

#include "Settings.h"

SwishyButton::SwishyButton(void)
{
	swishDir = 0;
	originSwishDir = 0;
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
	originSwishDir = p_swishDir;
	originX = x;
	originY = y;
	targetX = originX;
	targetY = originY;

	switch (swishDir)
	{
	case 0:
		x = -width * 2.0f;
		break;
	case 1:
		x = Settings::View::Width + width;
		break;
	case 2:
		y = -height * 2.0f;
		break;
	case 3:
		y = Settings::View::Height + height;
		break;
	}

	swishing = false;
}

SwishyButton::~SwishyButton(void)
{
}

void SwishyButton::Update(float f_dt)
{
	if (swishing)
	{
		switch (swishDir)
		{
		case 0:
			if (x < targetX)
			{
				x += 100 * f_dt;
			}
			if (x > targetX)
			{
				x = targetX;
				swishing = false;
			}
			break;
		case 1:
			if (x > targetX)
			{
				x -= 100 * f_dt;
			}
			if (x < targetX)
			{
				x = targetX;
				swishing = false;
			}
			break;
		case 2:
			if (y < targetY)
			{
				y += 100 * f_dt;
			}
			if (y > targetY)
			{
				y = targetY;
				swishing = false;
			}
			break;
		case 3:
			if (y > targetY)
			{
				y -= 100 * f_dt;
			}
			if (y > targetY)
			{
				y = targetY;
				swishing = false;
			}
			break;
		}
	}
}

void SwishyButton::SwishOn()
{
	targetX = originX;
	targetY = originY;

	switch (originSwishDir)
	{
	case 0:
		x = -width * 2.0f;
		break;
	case 1:
		x = Settings::View::Width + width;
		break;
	case 2:
		y = -height * 2.0f;
		break;
	case 3:
		y = Settings::View::Height + height;
		break;
	}

	swishDir = originSwishDir;
	swishing = true;
}

void SwishyButton::SwishOff()
{
	switch (originSwishDir)
	{
	case 0:
		swishDir = 1;
		targetX = -width * 2.0f;
		break;
	case 1:
		swishDir = 0;
		targetX = Settings::View::Width + width;
		break;
	case 2:
		swishDir = 3;
		targetY = -height * 2.0f;
		break;
	case 3:
		swishDir = 2;
		targetY = Settings::View::Height + height;
		break;
	}

	swishing = true;
}