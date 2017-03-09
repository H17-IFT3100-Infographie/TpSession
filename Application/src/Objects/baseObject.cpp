#include "baseObject.h"

BaseObject::BaseObject(float x, float y, float z)
	: pos(ofVec3f(x, y, z))
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
{
}

BaseObject::BaseObject(const ofVec3f& pos)
	: pos(pos)
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
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
}

void BaseObject::Draw()
{
}