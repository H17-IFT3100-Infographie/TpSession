#include "sphere.h"
// Constructeur de la classe sph�re sans param�tre et avec initialisation
Sphere::Sphere()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, radius(100)
{
	Load();
}
// Constructeur de la classe sph�re avec 4 param�tres, la position et le rayon
Sphere::Sphere(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
	, radius(radius)
{
	Load();
}
// Destructeur de la classe Sph�re
Sphere::~Sphere()
{
}
// Fonction permettant de charger certains param�tres de la sph�re
void Sphere::Load()
{
	primitive = new ofSpherePrimitive(radius, 5);
}
// Fonction permettant de d�terminer s'il y a collision entre le clic de souris et la sph�re
bool Sphere::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y && 
		   mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}