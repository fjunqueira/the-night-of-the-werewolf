#pragma once
#include "GameObject.h"

class Layer : public GameObject
{
private:
	int counter;
	Vector2 extractionPosition;
	Image* image;
public:
	Layer(Image* image, int zindex);
	Layer(Image* image, Vector2 position, int zindex);
	virtual void plotTo(Image * destination) override;
	virtual void update(int speed) override;
	~Layer();
};

