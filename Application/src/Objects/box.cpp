#include "box.h"

Box::Box()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, dimensions(1, 1, 1)
{

}

Box::Box(float x, float y, float z, int width, int height, int depth)
	: Base3DObject(x, y, z)
	, dimensions(width, height, depth)
{
	m_3dPrimitive = new ofBoxPrimitive(dimensions.x, dimensions.y, dimensions.z);
	m_3dPrimitive->setPosition(x, y, z);
}

Box::Box(const ofVec3f& position, int width, int height, int depth)
	: Base3DObject(position)
	, dimensions(width, height, depth)
{
	m_3dPrimitive = new ofBoxPrimitive(dimensions.x, dimensions.y, dimensions.z);
}

Box::~Box()
{
}

bool Box::IsHovered(float x, float y)
{
	return false;
}