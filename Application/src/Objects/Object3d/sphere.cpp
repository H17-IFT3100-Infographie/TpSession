#include "sphere.h"

Sphere::Sphere()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, radius(1)
{

}

Sphere::Sphere(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
	, radius(radius)
{
	m_3dPrimitive = new ofSpherePrimitive(radius, 5);
}

Sphere::~Sphere()
{
}