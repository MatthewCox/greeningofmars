#include "GameObject.h"

GameObject::GameObject(void)
{
}

GameObject::~GameObject(void)
{
}

Vector3f GameObject::Position() const
{
	return position;
}

void GameObject::Position( Vector3f p_position )
{
	position = p_position;
}