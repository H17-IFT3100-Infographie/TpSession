#include "baseObject.h"

BaseObject::BaseObject(float x, float y, float z, ofColor color)
	: pos(ofVec3f(x, y, z))
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
	, color(color)
{
}

BaseObject::BaseObject(const ofVec3f& pos, ofColor color)
	: pos(pos)
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
	, color(color)
{

}

BaseObject::~BaseObject()
{
}

void BaseObject::Setup()
{

}

void BaseObject::Update()
{
	ClampRotation();
}

void BaseObject::Draw()
{
}

void BaseObject::ClampRotation()
{
	if (rot.x > 359.0f)
		rot.x = rot.x - 360.0f;
	else if (rot.x < 0.0f)
		rot.x = 359.0f;

	if (rot.y > 359.0f)
		rot.y = rot.y - 360.0f;
	else if (rot.y < 0.0f)
		rot.y = 359.0f;

	if (rot.z > 359.0f)
		rot.z = rot.z - 360.0f;
	else if (rot.z < 0.0f)
		rot.z = 359.0f;
}