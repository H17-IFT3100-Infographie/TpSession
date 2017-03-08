#ifndef SPHERE_H
#define SPHERE_H

#include "baseObject.h"

class Sphere : public BaseObject
{
public:
	Sphere(int x, int y, int z, float radius);
	~Sphere();
	
	bool IsHovered(float x, float y);

private:
	Sphere();

	float radius;
};

#endif // SPHERE_H