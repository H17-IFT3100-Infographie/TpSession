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
	m_3dPrimitive = new ofBoxPrimitive(dimensions.x, dimensions.y, dimensions.z);
}

Box::~Box()
{
}

bool Box::Inside(int x, int y, int z, const ofEasyCam& cam)
{
	ofVec3f a = cam.worldToScreen(pos);
	ofLog() << x << "  " << y << "  " << a;
	return x >= pos.x && y >= pos.y && x <= pos.x + dimensions.x && y <= pos.y + dimensions.y;
}