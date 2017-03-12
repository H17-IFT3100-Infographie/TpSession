#include "sphere.h"
// Constructeur de la classe sphère sans paramètre et avec initialisation
Sphere::Sphere()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, radius(100)
{
	Load();
}
// Constructeur de la classe sphère avec 4 paramètres, la position et le rayon
Sphere::Sphere(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
	, radius(radius)
{
	Load();
}
// Destructeur de la classe Sphère
Sphere::~Sphere()
{
}
// Fonction permettant de charger certains paramètres de la sphère
void Sphere::Load()
{
	primitive = new ofSpherePrimitive(radius, 5);
}
// Fonction permettant de déterminer s'il y a collision entre le clic de souris et la sphère
bool Sphere::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y && 
		   mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}