#include "Image.h"

Image::Image(int w, int h) {
    this->width = w;
    this->height = h;
    this->pixels = new int[w * h]();
}

Image::Image(int w, int h, int *pixels) {
    this->width = w;
    this->height = h;
    this->pixels = new int[w * h];

    memcpy(this->pixels, pixels, w * h * sizeof(int));
}

void Image::extractAndPlotTo(Image *dest, Vector2 plotPos, Vector2 extractPos, Vector2 extractDim) {
    this->extractAndPlotTo(dest, plotPos.x, plotPos.y, extractPos.x, extractPos.y, extractDim.x, extractDim.y);
}

void Image::extractAndPlotTo(Image *dest, int plotStartingX, int plotStartingY, int extractStartingX,
                             int extractStartingY, int extractWidth, int extractHeight) {
    for (int x = 0; x < extractWidth; x++) {
        for (int y = 0; y < extractHeight; y++) {
            auto currentCutX = x + extractStartingX;
            auto currentCutY = y + extractStartingY;

            if (this->positionOutOfBounds(currentCutX, currentCutY))
                continue;

            auto pixel = this->getPixel(currentCutX, currentCutY);

            unsigned char alpha = (unsigned char) (pixel >> 24);

            auto currentPlotX = x + plotStartingX;
            auto currentPlotY = y + plotStartingY;

            if (dest->positionOutOfBounds(currentPlotX, currentPlotY))
                continue;

            if (alpha == 0)
                continue;
            else if (alpha == 255)
                dest->setPixel(pixel, currentPlotX, currentPlotY);
            else {
                auto channel2 = dest->getPixel(currentPlotX, currentPlotY);

                unsigned char r = this->applyTransparency((unsigned char) (channel2 >> 16),
                                                          (unsigned char) (pixel >> 16), alpha);
                unsigned char g = this->applyTransparency((unsigned char) (channel2 >> 8), (unsigned char) (pixel >> 8),
                                                          alpha);
                unsigned char b = this->applyTransparency((unsigned char) channel2, (unsigned char) pixel, alpha);

                dest->setPixel(r << 16 | g << 8 | b, currentPlotX, currentPlotY);
            }
        }
    }
}

void Image::plotTo(Image *dest, Vector2 position) {
    this->plotTo(dest, position.x, position.y);
}

void Image::plotTo(Image *dest, int startingX, int startingY) {
    this->extractAndPlotTo(dest, startingX, startingY, 0, 0, this->width, this->height);
}

void Image::plotTo(Image *dest) {
    return this->plotTo(dest, 0, 0);
}

Image *Image::extract(int startingX, int startingY, int width, int height) {
    auto result = new Image(width, height);

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            auto currentX = x + startingX;
            auto currentY = y + startingY;

            if (this->positionOutOfBounds(currentX, currentY))
                continue;

            result->setPixel(this->getPixel(currentX, currentY), x, y);
        }
    }

    return result;
}

bool Image::positionOutOfBounds(int posX, int posY) {
    return !(posX >= 0 && posX < this->width && posY >= 0 && posY < this->height);
}

unsigned char Image::applyTransparency(unsigned char channel1, unsigned char channel2, unsigned char alpha) {
    return (unsigned char) (channel1 * (1 - alpha) + channel2 * alpha);
}

void Image::setPixel(int rgb, int x, int y) {
    this->pixels[x + y * this->width] = rgb;
}

int Image::getPixel(int x, int y) {
    return this->pixels[x + y * this->width];
}

int *Image::getPixels() {
    return this->pixels;
}

int Image::getWidth() {
    return this->width;
}

int Image::getHeight() {
    return this->height;
}

Image::~Image() {
    delete[] this->pixels;
}