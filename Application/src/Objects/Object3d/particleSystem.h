#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "base3DObject.h"

class ParticleSystem : public Base3DObject
{
public:
	ParticleSystem();
	ParticleSystem(int x, int y, int z, float radius);
	~ParticleSystem();

private:
	void Load();
};

#endif // PARTICLE_SYSTEM_H