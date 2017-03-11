#include "line.h"

Line::Line(ofPoint p1, ofPoint p2, float stroke, ofColor color)
	: Primitive(p1, stroke, color)
	, endPoint(p2)
{

}

Line::~Line()
{

}

void Line::Setup()
{
}

void Line::Update()
{
}

void Line::Draw()
{
	PreDraw();

	ofDrawLine(pos, pos + endPoint);

	PostDraw();
}

void Line::DrawBoundingBox()
{
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	ofDrawRectangle(pos.x, pos.y, stroke, abs(pos.x - endPoint.x));

	ofSetColor(ofColor::white);
}

void Line::SetAlpha(int a)
{

}

bool Line::IsHovered(float x, float y)
{
	return false;
}