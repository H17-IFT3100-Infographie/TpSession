#include "sphere.h"

Sphere::Sphere()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, radius(100)
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
	primitive = new ofSpherePrimitive(radius, 5);
}

bool Sphere::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - radius * 0.5f && mouse.y >= objScreenPos.y - radius * 0.5f && 
		   mouse.x <= objScreenPos.x + radius * 0.5f && mouse.y <= objScreenPos.y + radius * 0.5f;
}