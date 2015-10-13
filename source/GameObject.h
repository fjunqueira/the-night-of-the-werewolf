#pragma once
#include "Vector2.h"
#include "Image.h"

class GameObject
{
protected:
	int zindex;
	Vector2 position;
public:
	GameObject();
	GameObject(int zindex);
	GameObject(Vector2 position, int zindex);

	void setPosition(Vector2 position);
	Vector2 getPosition();

	void setZ(int zindex);
	int getZ();

	virtual void update(int speed) = 0;

	bool operator < (const GameObject& object) const;
	bool operator > (const GameObject& object) const;

	virtual void plotTo(Image* image) = 0;
	virtual ~GameObject() = 0;
};

