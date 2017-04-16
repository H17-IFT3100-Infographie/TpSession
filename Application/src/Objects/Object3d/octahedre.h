#ifndef OCTAHEDRE_H
#define OCTAHEDRE_H

#include "base3DObject.h"
#include "ofMesh.h"
// Look how to draw a mesh custom:
// http://openframeworks.cc/documentation/3d/ofMesh/
class Octahedre : public Base3DObject
{
public:
	Octahedre();
	Octahedre(int x, int y, int z, float radius);
	~Octahedre();

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

#endif // OCTAHEDRE_H