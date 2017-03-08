#include "circle.h"

Circle::Circle(ofPoint center, float radius, float stroke, bool fill, ofColor color)
	: Primitive(center, stroke, fill, color)
	, radius(radius)
{

}

Circle::~Circle()
{

}

void Circle::Setup()
{
}

void Circle::Update()
{
}

void Circle::Draw()
{
	PreDraw();

	ofDrawCircle(pos, radius);
	
	PostDraw();
}

void Circle::SetColor(int r, int g, int b)
{

}

void Circle::SetAlpha(int a)
{

}

bool Circle::IsHovered(float x, float y)
{
	return false;
}