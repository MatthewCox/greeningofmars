#include "SwishyButton.h"

#include <stdlib.h>

#include <GL/freeglut.h>

#include <FTGL/ftgl.h>

#include "../Maths/Vector2f.h"
#include "../Game Components/Settings.h"

SwishyButton::SwishyButton(void)
{
	swishDir = 0;
	originSwishDir = 0;
}
SwishyButton::SwishyButton(Vector2f p_position,
						   Vector2f p_size,
						   char* p_name, char* p_fontPath,
						   ColourA p_colour,
						   int p_swishDir) : Button(
						   p_position,
						   p_size,
						   p_name, p_fontPath,
						   p_colour)
{
	swishDir = p_swishDir;
	originSwishDir = p_swishDir;
	origin = position;
	target = origin;

	switch (swishDir)
	{
	case 0:
		position = Vector2f(-size.X() * 2.0f, target.Y());
		label->SetPosition(position + (size * 0.5f));
		break;
	case 1:
		position = Vector2f(Settings::View::Width + size.X(), target.Y());
		label->SetPosition(position + (size * 0.5f));
		break;
	case 2:
		position = Vector2f(target.X(), -size.Y() * 2.0f);
		label->SetPosition(position + (size * 0.5f));
		break;
	case 3:
		position = Vector2f(target.X(), Settings::View::Height + size.Y());
		label->SetPosition(position + (size * 0.5f));
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
				position += Vector2f(100.0f * f_dt, 0.0f);
				label->SetPosition(position + (size * 0.5f));
			}
			if (position.X() > target.X())
			{
				position = target;
				label->SetPosition(position + (size * 0.5f));
				swishing = false;
			}
			break;
		case 1:
			if (position.X() > target.X())
			{
				position -= Vector2f(100.0f * f_dt, 0.0f);
				label->SetPosition(position + (size * 0.5f));
			}
			if (position.X() < target.X())
			{
				position = target;
				label->SetPosition(position + (size * 0.5f));
				swishing = false;
			}
			break;
		case 2:
			if (position.Y() < target.Y())
			{
				position += Vector2f(0.0f, 100.0f * f_dt);
				label->SetPosition(position + (size * 0.5f));
			}
			if (position.Y() > target.Y())
			{
				position = target;
				label->SetPosition(position + (size * 0.5f));
				swishing = false;
			}
			break;
		case 3:
			if (position.Y() > target.Y())
			{
				position -= Vector2f(0.0f, 100.0f * f_dt);
				label->SetPosition(position + (size * 0.5f));
			}
			if (position.Y() < target.Y())
			{
				position = target;
				label->SetPosition(position + (size * 0.5f));
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
		position = Vector2f(-size.X() * 2.0f, target.Y());
		label->SetPosition(position + (size * 0.5f));
		break;
	case 1:
		position = Vector2f(Settings::View::Width + size.X(), target.Y());
		label->SetPosition(position + (size * 0.5f));
		break;
	case 2:
		position = Vector2f(target.X(), -size.Y() * 2.0f);
		label->SetPosition(position + (size * 0.5f));
		break;
	case 3:
		position = Vector2f(target.X(), Settings::View::Height + size.Y());
		label->SetPosition(position + (size * 0.5f));
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
		target = Vector2f(-size.X() * 2.0f, origin.Y());
		break;
	case 1:
		swishDir = 0;
		target = Vector2f(Settings::View::Width + size.X(), origin.Y());
		break;
	case 2:
		swishDir = 3;
		target = Vector2f(origin.X(), -size.Y() * 2.0f);
		break;
	case 3:
		swishDir = 2;
		target = Vector2f(origin.X(), Settings::View::Height + size.Y());
		break;
	}

	swishing = true;
}