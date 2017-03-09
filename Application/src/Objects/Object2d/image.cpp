#include "image.h"

Image::Image(const std::string filepath)
	: BaseObject(0.0f, 0.0f, 0.0f)
	, filepath(filepath)
{
	Load();
}

Image::Image(float x, float y, float z, const std::string filepath)
	: BaseObject(x, y, z)
	, filepath(filepath)
{
	Load();
}

Image::~Image()
{
	delete image;
	image = nullptr;
}

void Image::Load()
{
	image = new ofImage();
	image->load(filepath);
}

void Image::Setup()
{
	originalDimension = ofVec3f(image->getWidth(), image->getHeight(), 0.0f);

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
	image->update();
}

void Image::Draw()
{
	image->setAnchorPoint(image->getWidth() * 0.5f, image->getHeight() * 0.5f);
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