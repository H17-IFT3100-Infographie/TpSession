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

	Setup();
}

void Image::Setup()
{
	originalDimension = ofVec3f(image->getWidth(), image->getHeight(), 0.0f);

	originalColor.clear();
	for (int i = 0; i < image->getWidth(); i++)
	{
		originalColor.push_back(std::vector<ofColor>());
		for (int j = 0; j < image->getHeight(); j++)
		{
			originalColor[i].push_back(image->getColor(i, j));
		}
	}

	boundingBox = new Rect(ofPoint(pos.x, pos.y, pos.z), image->getWidth(), image->getHeight(), 1.0f, false, ofColor::green);
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

void Image::DrawBoundingBox() 
{
	boundingBox->pos = ofVec3f(pos.x - image->getWidth() * 0.5f, pos.y - image->getHeight() * 0.5f, pos.z);
	boundingBox->SetDimension(image->getWidth(), image->getHeight());
	boundingBox->DrawBoundingBox();
}

void Image::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

	for (int i = 0; i < image->getWidth(); i++)
	{
		for (int j = 0; j < image->getHeight(); j++)
		{
			ofColor finalColor = image->getColor(i, j);
			finalColor.r = (originalColor[i][j].r + color.r) / 2;
			finalColor.g = (originalColor[i][j].g + color.g) / 2;
			finalColor.b = (originalColor[i][j].b + color.b) / 2;
			finalColor.a = color.a;

			image->setColor(i, j, finalColor);
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
 
bool Image::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return mouse.x >= objScreenPos.x - image->getWidth() * 0.25f && mouse.y >= objScreenPos.y - image->getHeight() * 0.25f && mouse.x <= objScreenPos.x + image->getWidth() * 0.25f && mouse.y <= objScreenPos.y + image->getHeight() * 0.25f;
}

