#ifndef TETHRAHEDRON_H
#define TETHRAHEDRON_H

#include "base3DObject.h"

// Look how to draw a mesh custom:
// http://openframeworks.cc/documentation/3d/ofMesh/
class Tethrahedron : public Base3DObject
{
public:
	Tethrahedron();
	Tethrahedron(int x, int y, int z, float radius);
	~Tethrahedron();

private:
	void Load();
};

#endif // TETHRAHEDRON_H