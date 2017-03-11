#include "rect.h"

Rect::Rect(ofPoint tl, float width, float height, float lineStroke, bool fill, ofColor color)
	: Primitive(tl, lineStroke, fill, color)
	, width(width)
	, height(height)
{

}

Rect::~Rect()
{

}

void Rect::Setup()
{
}

void Rect::Update()
{
}

void Rect::Draw()
{
	PreDraw();
	
	ofDrawRectangle(pos.x, pos.y, width, height);
	
	PostDraw();
}

void Rect::DrawBoundingBox()
{
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	ofDrawRectangle(pos.x, pos.y, width, height);

	ofSetColor(ofColor::white);
}

bool Rect::IsHovered(float x, float y)
{
	return false;
}