#include "particleSystem.h"
//TODO
// Constructeur de la classe ParticleSystem
ParticleSystem::ParticleSystem()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}
ParticleSystem::ParticleSystem(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}
// Destructeur de la classe ParticleSystem 
ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Load()
{

}