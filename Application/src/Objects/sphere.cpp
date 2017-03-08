#include "sphere.h"

Sphere::Sphere()
{

}

Sphere::Sphere(int x, int y, int z, float radius)
	: BaseObject(x, y, z)
	, radius(radius)
{
	m_3dPrimitive = new ofSpherePrimitive(radius, 5);
}

Sphere::~Sphere()
{
}

bool Sphere::IsHovered(float x, float y)
{
	return false;
}