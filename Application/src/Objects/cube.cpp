#include "cube.h"

Box::Box()
{

}

Box::Box(int x, int y, int z, int width, int height, int depth)
	: BaseObject(x, y, z)
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