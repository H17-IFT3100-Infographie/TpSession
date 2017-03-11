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

bool Rect::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - height * 0.5f && mouse.x <= objScreenPos.x + width * 0.5f && mouse.y <= objScreenPos.y;
}
