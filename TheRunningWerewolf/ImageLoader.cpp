#include "ImageLoader.h"

ImageLoader::ImageLoader()
{
}

PTMInfo ImageLoader::loadPTM(char* filePath)
{
	auto ptmInfo = PTMInfo();

	string line;

	ifstream file(filePath, ios::binary);

	if (file.is_open())
	{
		file >> ptmInfo.magicNum;

		if ((file >> std::ws).peek() == std::char_traits<char>::to_int_type('#'))
			file >> ptmInfo.comment;

		if (ptmInfo.magicNum != "P8")
			throw logic_error("Only P8 PTMs can be loaded");

		file >> ptmInfo.width >> ptmInfo.height >> ptmInfo.maxval;

		file.get();

		int length = ptmInfo.width * ptmInfo.height;

		ptmInfo.pixels = new int[length];

		int unpackedLength = length * 4;

		unsigned char* buff = new unsigned char[unpackedLength];

		file.read((char*)buff, unpackedLength);

		int unpackedWidth = ptmInfo.width * 4;

		int index = 0;
		for (int i = unpackedLength - unpackedWidth; i >= 0; i -= unpackedWidth)
		{
			for (size_t y = 0; y < ptmInfo.width; y++)
			{
				ptmInfo.pixels[index] = (buff[i + (4 * y)] << 24) | (buff[(i + (4 * y)) + 1] << 16) | (buff[(i + (4 * y)) + 2] << 8) | (buff[(i + (4 * y)) + 3]);
				index++;
			}
		}

		delete[] buff;
		return ptmInfo;
	}

	else cout << "Unable to open file";

	throw std::exception("Unable to open file");
}

ImageLoader::~ImageLoader()
{
}