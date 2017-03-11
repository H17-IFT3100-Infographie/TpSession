#include "Base3DObject.h"

Base3DObject::Base3DObject(float x, float y, float z)
	: BaseObject(x, y, z)
{
}

Base3DObject::Base3DObject(const ofVec3f& pos) 
	: BaseObject(pos)
{

}

Base3DObject::~Base3DObject()
{
	if (nullptr != m_3dPrimitive)
	{
		delete m_3dPrimitive;
		m_3dPrimitive = nullptr;
	}
}

void Base3DObject::Draw()
{
	ofSetColor(color);

	m_3dPrimitive->setScale(scale);
	m_3dPrimitive->setPosition(pos);
	m_3dPrimitive->setOrientation(rot);
	m_3dPrimitive->draw();

	ofSetColor(ofColor::white);
}

bool Base3DObject::IsHovered(float x, float y)
{
	return false;
}