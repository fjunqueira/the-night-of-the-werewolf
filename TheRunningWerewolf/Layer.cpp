#include "Layer.h"

Layer::Layer(Image * image, int zindex) : GameObject(zindex), image(image)
{
}

Layer::Layer(Image * image, Vector2 position, int zindex) : GameObject(position, zindex), image(image)
{
}

Layer::~Layer()
{
}

void Layer::plotTo(Image * destination)
{
	this->image->extractAndPlotTo(destination, this->position, this->extractionPosition, Vector2(destination->getWidth(), this->image->getHeight()));
}

void Layer::update(int speed)
{
	this->extractionPosition.x = (++this->counter * speed * zindex);

	if (this->extractionPosition.x >= this->image->getWidth() / 2)
	{
		this->counter = 1;
		this->extractionPosition.x = this->counter * speed * zindex;
	}
}
