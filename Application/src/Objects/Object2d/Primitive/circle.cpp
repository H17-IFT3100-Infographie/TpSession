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

	ofPushMatrix();
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofDrawCircle(pos, radius * scale.x);
	ofPopMatrix();

	PostDraw();
}

void Circle::DrawBoundingBox()
{
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	ofDrawRectangle(pos.x - radius * scale.x, pos.y - radius * scale.x, radius * scale.x * 2.0f, radius * scale.x * 2.0f);

	ofSetColor(ofColor::white);
}

void Circle::SetAlpha(int a)
{

}

bool Circle::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y && 
		   mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}