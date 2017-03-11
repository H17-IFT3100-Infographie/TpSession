#include "box.h"

Box::Box()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, dimensions(100, 100, 100)
{
	Load();
}

Box::Box(float x, float y, float z, int width, int height, int depth)
	: Base3DObject(x, y, z)
	, dimensions(width, height, depth)
{
	Load();
}

Box::Box(const ofVec3f& position, int width, int height, int depth)
	: Base3DObject(position)
	, dimensions(width, height, depth)
{
	Load();
}

void Box::Load()
{
	primitive = new ofBoxPrimitive(dimensions.x, dimensions.y, dimensions.z);
}

Box::~Box()
{
}

bool Box::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - dimensions.x * 0.5f && mouse.y >= objScreenPos.y - dimensions.y * 0.5f && 
		   mouse.x <= objScreenPos.x + dimensions.x * 0.5f && mouse.y <= objScreenPos.y + dimensions.y * 0.5f;
}