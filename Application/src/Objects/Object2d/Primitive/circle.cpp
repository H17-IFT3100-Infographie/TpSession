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

void Circle::DrawBoundingBox()
{
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	ofDrawCircle(pos, radius);

	ofSetColor(ofColor::white);
}

void Circle::SetAlpha(int a)
{

}

bool Circle::IsHovered(float x, float y)
{
	return false;
}