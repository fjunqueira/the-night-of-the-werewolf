#pragma once

#include <algorithm>
#include "ImageLoader.h"
#include "Image.h"
#include <string>
#include <map>

class AssetManager {
private:
    std::map<std::string, Image *> assets;

    Image *loadImage(ImageLoader *loader, const char *path);

    void loadWolf(ImageLoader *loader);

    void loadWolfJump(ImageLoader *loader);

    void loadCop(ImageLoader *loader);

public:

    AssetManager();

    void loadAssets();

    Image *getAsset(std::string name);

    ~AssetManager();
};

