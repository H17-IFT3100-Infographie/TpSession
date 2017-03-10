#include "particleSystem.h"

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

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Load()
{

}