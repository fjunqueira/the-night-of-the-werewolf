#pragma once
#include "GameObject.h"
#include "Animation.h"

class Player : public GameObject
{
private:
	Animation running;
	Animation jumping;
	Animation current;
	bool isJumping;
	bool falling;
	bool dead;
	int getMaxHeight(int zindex);
	int getMinHeight(int zindex);
public:
	Player(Animation running, Animation jumping);
	Player(Animation running, Animation jumping, Vector2 position, int zindex);

	void Die();
	bool isDead();

	void revive();

	void handleInput(unsigned char key);
	virtual void update(int speed) override;
	virtual void plotTo(Image * destination) override;

	virtual ~Player();
};

