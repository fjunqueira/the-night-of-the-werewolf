#include "Animation.h"

Animation::Animation(int numberOfFrames, Image **frames) : numberOfFrames(numberOfFrames), frames(frames),
                                                           currentFrame() {
}

Image *Animation::getNextFrame() {
    if (this->currentFrame >= this->numberOfFrames - 1)
        this->currentFrame = 0;

    auto nextFrame = this->frames[currentFrame];

    this->currentFrame++;

    return nextFrame;
}

Image *Animation::getPriorFrame() {
    if (this->currentFrame < 0)
        this->currentFrame = this->numberOfFrames - 1;

    auto priorFrame = this->frames[currentFrame];

    this->currentFrame--;

    return priorFrame;
}

Image *Animation::getByNumber(int frameNumber) {
    return this->frames[frameNumber];
}

Animation::~Animation() {
}
