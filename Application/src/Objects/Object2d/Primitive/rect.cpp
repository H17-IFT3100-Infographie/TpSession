#include "rect.h"

Rect::Rect(ofPoint tl, ofPoint br, float lineStroke, bool fill, ofColor color)
	: Primitive(tl, lineStroke, fill, color)
	, bottomRight(br)
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
	
	ofDrawRectangle(ofRectangle(pos, bottomRight));
	
	PostDraw();
}

bool Rect::IsHovered(float x, float y)
{
	return false;
}