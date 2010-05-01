#include "UIObject.h"

UIObject::UIObject(void)
{
	position = Vector2f(0.0f, 0.0f);
}

UIObject::~UIObject(void)
{
}

void UIObject::SetPosition(Vector2f p_position)
{
	position = p_position;
}