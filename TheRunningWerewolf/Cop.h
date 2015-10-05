#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Animation.h"
#include "Player.h"

class Cop : public GameObject
{
private:
	Animation idle;
	Player* player;
public:

	Cop(Animation idle, Vector2 position, int zindex, Player* player);

	virtual void update(int speed) override;

	virtual void plotTo(Image * image) override;

	virtual ~Cop();
};

