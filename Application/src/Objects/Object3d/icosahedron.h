#ifndef Icosahedron_H
#define Icosahedron_H

#include "base3DObject.h"
#include "ofMesh.h"
// Look how to draw a mesh custom:
// http://openframeworks.cc/documentation/3d/ofMesh/
class Icosahedron : public Base3DObject
{
public:
	Icosahedron();
	Icosahedron(int x, int y, int z, float radius);
	~Icosahedron();
	Icosahedron(int x1, int y1, int x2,int y2, int x3,int y3, int x4,int y4);

	virtual void DrawBoundingBox();

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

private:
	void Setup();
	void Draw();

	void Load();

	ofMesh mesh;
	ofVbo vbo;
	float ang;
	float radius;
};

#endif // Icosahedron_H