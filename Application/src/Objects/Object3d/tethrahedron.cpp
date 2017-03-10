#include "tethrahedron.h"

Tethrahedron::Tethrahedron()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}

Tethrahedron::Tethrahedron(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}

Tethrahedron::~Tethrahedron()
{
}

void Tethrahedron::Load()
{

}