#ifndef Tetrahedron_H
#define Tetrahedron_H

#include "base3DObject.h"
#include "ofMesh.h"
// Look how to draw a mesh custom:
// http://openframeworks.cc/documentation/3d/ofMesh/
class Tetrahedron : public Base3DObject
{
public:
	ofMesh mesh;
	ofVbo vbo;

	Tetrahedron();
	Tetrahedron(int x, int y, int z, float radius);
	~Tetrahedron();
	Tetrahedron(int x1, int y1, int x2,int y2, int x3,int y3, int x4,int y4);

	virtual void DrawBoundingBox();
private:
	void Setup();
	void Draw();
	

	void Load();
};

#endif // Tetrahedron_H