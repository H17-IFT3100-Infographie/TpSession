#ifndef SPHERE_H
#define SPHERE_H

#include "base3DObject.h"

class Sphere : public Base3DObject
{
public:
	Sphere(int x, int y, int z, float radius);
	~Sphere();

private:
	Sphere();

	float radius;
};

#endif // SPHERE_H