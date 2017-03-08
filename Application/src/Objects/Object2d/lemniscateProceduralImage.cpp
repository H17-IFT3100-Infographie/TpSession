#include "lemniscateProceduralImage.h"

LemniscateProceduralImage::LemniscateProceduralImage()
	: Image(0.0f, 0.0f, 0.0f, "blankcanvas.jpg")
{
}

LemniscateProceduralImage::LemniscateProceduralImage(float x, float y, float z)
	: Image(x, y, z, "blankcanvas.jpg")
{
}

LemniscateProceduralImage::~LemniscateProceduralImage()
{
	delete image;
	image = nullptr;
}

void LemniscateProceduralImage::Setup()
{
	float length = image->getWidth() * 0.5f;
	// draw the lemniscate pattern
	for (float t = 0; t<360; t++) 
	{
		float x = image->getWidth()*0.5f + (length * cos(ofDegToRad(t))) / (1 + pow(sin(ofDegToRad(t)), 2)); // x position
		float y = image->getHeight() * 0.5f + (length * sin(ofDegToRad(t)) * cos(ofDegToRad(t))) / (1 + pow(sin(ofDegToRad(t)), 2)); // y position
		image->setColor(x, y, ofColor(0, 0, 0));
	}

	Image::Setup();
}