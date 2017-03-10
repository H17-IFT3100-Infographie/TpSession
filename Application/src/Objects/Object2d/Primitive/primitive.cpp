#include "primitive.h"

Primitive::Primitive(ofPoint pos, float stroke, ofColor color)
	: BaseObject(pos.x, pos.y, pos.z)
	, stroke(stroke)
	, fill(false)
{

}

Primitive::Primitive(ofPoint pos, float stroke, bool fill, ofColor color)
	: BaseObject(pos.x, pos.y, pos.z)
	, stroke(stroke)
	, fill(fill)
{

}

Primitive::~Primitive()
{

}

void Primitive::Setup()
{
}

void Primitive::Update()
{
}

void Primitive::PreDraw()
{
	ofSetColor(color);
	ofSetLineWidth(stroke);
}

void Primitive::Draw()
{
	
}

void Primitive::PostDraw()
{
	if (fill)
		ofFill();
	else
		ofNoFill();

	ofSetLineWidth(1.0f);
	ofSetColor(ofColor::white);
}

void Primitive::SetAlpha(int a)
{

}

bool Primitive::IsHovered(float x, float y)
{
	return false;
}