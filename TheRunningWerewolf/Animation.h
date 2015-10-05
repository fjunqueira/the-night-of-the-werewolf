#pragma once
#include "Image.h"
class Animation
{
private:
	int numberOfFrames, currentFrame;
	Image** frames;
public:
	Animation(int numberOfFrames, Image** frames);
	Image* getNextFrame();
	Image* getPriorFrame();
	Image* getByNumber(int frameNumber);
	~Animation();
};

