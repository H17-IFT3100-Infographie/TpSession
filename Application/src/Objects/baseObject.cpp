#include "baseObject.h"

BaseObject::BaseObject(float x, float y, float z)
	: pos(ofVec3f(x, y, z))
{
}

BaseObject::BaseObject(const ofVec3f& pos)
	: pos(pos)
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