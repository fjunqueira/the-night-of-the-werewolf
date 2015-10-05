#pragma once
#include "ImageLoader.h"
#include "Image.h"
#include <map>

class AssetManager
{
private:
	std::map<char*, Image*> assets;

	Image* loadImage(ImageLoader* loader, char* path);

	void loadWolf(ImageLoader* loader);

	void loadWolfJump(ImageLoader * loader);

	void loadCop(ImageLoader * loader);

public:

	AssetManager();

	void loadAssets();

	Image* getAsset(char* name);
	
	~AssetManager();
};

