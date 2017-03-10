#include "sphere.h"

Sphere::Sphere()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, radius(1)
{
	Load();
}

Sphere::Sphere(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
	, radius(radius)
{
	Load();
}

Sphere::~Sphere()
{
}

void Sphere::Load()
{
	m_3dPrimitive = new ofSpherePrimitive(radius, 5);
}