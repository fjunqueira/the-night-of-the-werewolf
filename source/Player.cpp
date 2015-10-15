#include "Player.h"

Player::Player(Animation running, Animation jumping) : GameObject(), running(running), jumping(jumping), current(running)
{
}

Player::Player(Animation running, Animation jumping, Vector2 position, int zindex) : GameObject(position, zindex), running(running), jumping(jumping), current(running)
{
}

void Player::Die()
{
	this->dead = true;
}

bool Player::isDead()
{
	return this->dead;
}

void Player::revive()
{
	this->dead = false;
}

void Player::handleInput(unsigned char key)
{
	if (!this->isJumping)
		switch (key)
		{
		case ' ':
			this->isJumping = true;
			this->current = this->jumping;
			break;
		default:
			break;
		}
}

void Player::update(int speed)
{
	//depending on the layer, the max and min values change
	int maxHeight = this->getMaxHeight(zindex);
	int minHeight = this->getMinHeight(zindex);;

	if (this->isJumping)
	{
		this->position.y += 50 * (falling ? -1 : 1);

		//switches the index when the max height is reached
		if (this->position.y >= maxHeight)
		{
			this->falling = true;
			this->zindex = zindex == 5 ? 7 : 5;

			//clamps the position to the max height
			this->position.y = this->getMaxHeight(this->zindex);
		}

		if (this->position.y <= minHeight)
		{
			this->isJumping = false;
			this->falling = false;
			this->current = this->running;

			//clamps the position to the min height
			this->position.y = this->getMinHeight(this->zindex);
		}
	}
}

int Player::getMaxHeight(int zindex)
{
	return zindex == 5 ? 210 : 205;
}

int Player::getMinHeight(int zindex)
{
	return zindex == 7 ? 90 : 85;
}

void Player::plotTo(Image * destination)
{
	this->current.getNextFrame()->plotTo(destination, this->position);
}

Player::~Player()
{
}
