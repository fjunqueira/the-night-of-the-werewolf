#include "Cop.h"

Cop::Cop(Animation idle, Vector2 position, int zindex, Player* player) :GameObject(position, zindex), idle(idle), player(player)
{
}

void Cop::update(int speed)
{
	this->position.x -= speed * 4;

	auto distanceFromPlayer = (this->position - this->player->getPosition()).getMagnitude();

	if (distanceFromPlayer < 70 && this->zindex == this->player->getZ())
		player->Die();
}

void Cop::plotTo(Image * image)
{
	this->idle.getNextFrame()->plotTo(image, this->position);
}

Cop::~Cop()
{
}
