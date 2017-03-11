#ifndef SPHERE_H
#define SPHERE_H

#include "base3DObject.h"

class Sphere : public Base3DObject
{
public:
	Sphere();
	Sphere(int x, int y, int z, float radius);
	~Sphere();

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

private:
	void Load();

	float radius;
};

#endif // SPHERE_H