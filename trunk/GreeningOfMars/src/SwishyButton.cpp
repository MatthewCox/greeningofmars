#include "SwishyButton.h"

#include <stdlib.h>

#include <GL/freeglut.h>

#include <FTGL/ftgl.h>

#include "Settings.h"

SwishyButton::SwishyButton(void)
{
	swishDir = 0;
	originSwishDir = 0;
}
SwishyButton::SwishyButton(Vector2f p_position,
						   Vector2f p_size,
						   char* p_name, char* p_fontPath,
						   int p_swishDir) : Button(
						   p_position,
						   p_size,
						   p_name, p_fontPath)
{
	swishDir = p_swishDir;
	originSwishDir = p_swishDir;
	origin = position;
	target = origin;

	switch (swishDir)
	{
	case 0:
		position = Vector2f(-size.X() * 2.0f, 0.0f);
		break;
	case 1:
		position = Vector2f(Settings::View::Width + size.X(), 0.0f);
		break;
	case 2:
		position = Vector2f(0.0f, -size.Y() * 2.0f);
		break;
	case 3:
		position = Vector2f(0.0f, Settings::View::Height + size.Y());
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
			if (position.X() < target.X())
			{
				position = position + Vector2f(100.0f * f_dt, 0.0f);
			}
			if (position.X() > target.X())
			{
				position = target;
				swishing = false;
			}
			break;
		case 1:
			if (position.X() > target.X())
			{
				position = position - Vector2f(100.0f * f_dt, 0.0f);
			}
			if (position.X() < target.X())
			{
				position = target;
				swishing = false;
			}
			break;
		case 2:
			if (position.Y() < target.Y())
			{
				position = position + Vector2f(0.0f, 100.0f * f_dt);
			}
			if (position.Y() > target.Y())
			{
				position = target;
				swishing = false;
			}
			break;
		case 3:
			if (position.Y() > target.Y())
			{
				position = position - Vector2f(0.0f, 100.0f * f_dt);
			}
			if (position.Y() < target.Y())
			{
				position = target;
				swishing = false;
			}
			break;
		}
	}
}

void SwishyButton::SwishOn()
{
	target = origin;

	switch (originSwishDir)
	{
	case 0:
		position = Vector2f(-size.X() * 2.0f, 0.0f);
		break;
	case 1:
		position = Vector2f(Settings::View::Width + size.X(), 0.0f);
		break;
	case 2:
		position = Vector2f(0.0f, -size.Y() * 2.0f);
		break;
	case 3:
		position = Vector2f(0.0f, Settings::View::Height + size.Y());
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
		target = Vector2f(-size.X() * 2.0f, 0.0f);
		break;
	case 1:
		swishDir = 0;
		target = Vector2f(Settings::View::Width + size.X(), 0.0f);
		break;
	case 2:
		swishDir = 3;
		target = Vector2f(0.0f, -size.Y() * 2.0f);
		break;
	case 3:
		swishDir = 2;
		target = Vector2f(0.0f, Settings::View::Height + size.Y());
		break;
	}

	swishing = true;
}