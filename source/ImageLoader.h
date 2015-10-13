#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

struct PTMInfo
{
	string magicNum, comment;
	int width, height, maxval;
	int* pixels;
};

class ImageLoader
{
public:
	ImageLoader();

	PTMInfo loadPTM(const char* filePath);

	~ImageLoader();
};