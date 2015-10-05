#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(int zindex) : zindex(zindex)
{
}

GameObject::GameObject(Vector2 position, int zindex) : position(position), zindex(zindex)
{
}

void GameObject::setPosition(Vector2 position)
{
	this->position = position;
}

Vector2 GameObject::getPosition()
{
	return this->position;
}

void GameObject::setZ(int zindex)
{
	this->zindex = zindex;
}

int GameObject::getZ()
{
	return this->zindex;
}

bool GameObject::operator<(const GameObject & object) const
{
	return (zindex < object.zindex);
}

bool GameObject::operator>(const GameObject & object) const
{
	return (zindex > object.zindex);
}

GameObject::~GameObject()
{
}
