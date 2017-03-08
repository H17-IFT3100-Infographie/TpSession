#include "baseObject.h"

BaseObject::BaseObject()
	: position(ofVec3f(0.0f, 0.0f, 0.0f))
{

}

BaseObject::BaseObject(float x, float y, float z)
	: position(ofVec3f(x, y, z))
{

}

BaseObject::~BaseObject()
{
}

void BaseObject::Draw()
{
	m_3dPrimitive->setPosition(position);
	m_3dPrimitive->draw();
}