#include "cube.h"

Box::Box()
{

}

Box::Box(int x, int y, int z, int width, int height, int depth)
	: BaseObject(x, y, z)
{
	m_3dPrimitive = new ofBoxPrimitive(width, height, depth);
}

Box::~Box()
{
}