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
	if (nullptr != primitive)
	{
		delete primitive;
		primitive = nullptr;
	}
}

void Base3DObject::Draw()
{
	ofSetColor(color);

	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	primitive->draw();

	ofSetColor(ofColor::white);
}

void Base3DObject::DrawBoundingBox()
{
	ofSetColor(ofColor::green);
	
	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	primitive->drawWireframe();

	ofSetColor(ofColor::white);
}