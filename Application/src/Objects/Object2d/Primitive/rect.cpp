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

bool Rect::IsHovered(float x, float y)
{
	return false;
}