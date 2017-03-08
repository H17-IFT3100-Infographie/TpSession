#include "image.h"

Image::Image(const std::string filepath)
	: BaseObject(0.0f, 0.0f, 0.0f)
	, filepath(filepath)
{
	image = new ofImage();
	image->load(filepath);
}

Image::Image(float x, float y, float z, const std::string filepath)
	: BaseObject(x, y, z)
	, filepath(filepath)
{
	image = new ofImage();
	image->load(filepath);
}

Image::~Image()
{
	delete image;
	image = nullptr;
}

void Image::Draw()
{
	image->draw(pos.x, pos.y, pos.z, image->getWidth(), image->getHeight());
}

bool Image::IsHovered(float x, float y)
{
	return false;
}