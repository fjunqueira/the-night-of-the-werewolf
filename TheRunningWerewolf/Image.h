#pragma once
#include <string.h>
#include <stdexcept>
#include "Vector2.h"

class Image {
private:
	int* pixels;

	int width, height;

	unsigned char applyTransparency(unsigned char channel, unsigned char alpha);

	bool positionOutOfBounds(int posX, int posY);

public:

	Image(int w, int h);

	Image(int w, int h, int * pixels);

	void extractAndPlotTo(Image * dest, Vector2 plotPos, Vector2 extractPos, Vector2 extractDim);

	void extractAndPlotTo(Image* dest, int plotStartingX, int plotStartingY, int extractStartingX, int extractStartingY, int extractWidth, int extractHeight);

	void plotTo(Image * dest, Vector2 position);

	void plotTo(Image* dest, int startingX, int startingY);

	void plotTo(Image* dest);

	Image* extract(int offsetX, int offsetY, int width, int height);

	void setPixel(int rgb, int x, int y);

	int getPixel(int x, int y);

	int* getPixels();

	int getWidth();

	int getHeight();

	~Image();
};