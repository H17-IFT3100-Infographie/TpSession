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

void Image::Setup()
{
	for (int i = 0; i < image->getWidth(); i++)
	{
		originalColor.push_back(std::vector<ofColor>());
		for (int j = 0; j < image->getHeight(); j++)
		{
			originalColor[i].push_back(image->getColor(i, j));
		}
	}
}

void Image::Update()
{
	//image->setImageType(ofImageType::OF_IMAGE_COLOR_ALPHA);
	image->update();
}

void Image::Draw()
{
	image->draw(pos.x, pos.y, pos.z, image->getWidth(), image->getHeight());
}

void Image::SetColor(int r, int g, int b)
{
	for (int i = 0; i < image->getWidth(); i++)
	{
		for (int j = 0; j < image->getHeight(); j++)
		{
			ofColor color = image->getColor(i, j);
			color.r = (originalColor[i][j].r + r) / 2;
			color.g = (originalColor[i][j].g + g) / 2;
			color.b = (originalColor[i][j].b + b) / 2;

			image->setColor(i, j, color);
		}
	}
}

void Image::SetAlpha(int a)
{
	for (int i = 0; i < image->getWidth(); i++)
	{
		for (int j = 0; j < image->getHeight(); j++)
		{
			ofColor color = image->getColor(i, j);
			color.a = a;
			image->setColor(i, j, color);
		}
	}
}

bool Image::IsHovered(float x, float y)
{
	return false;
}