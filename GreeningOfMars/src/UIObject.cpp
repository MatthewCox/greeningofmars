#include "UIObject.h"

UIObject::UIObject(void)
{
	position = Vector2f(0.0f, 0.0f);
	colour = ColourA(1.0f);
}

UIObject::~UIObject(void)
{
}

void UIObject::SetPosition(Vector2f p_position)
{
	position = p_position;
}

void UIObject::SetColour(ColourA p_colour)
{
	colour = p_colour;
}