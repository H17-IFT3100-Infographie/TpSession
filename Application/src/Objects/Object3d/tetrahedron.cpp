#include "tetrahedron.h"

Tetrahedron::Tetrahedron()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}

Tetrahedron::Tetrahedron(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}

Tetrahedron::~Tetrahedron()
{
}
Tetrahedron::Tetrahedron(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) : Base3DObject(x1, y1, 0)
{
	Load();
}
void Tetrahedron::Load()
{
	ofMesh mesh; 
	
	char c[] = "100110010101";
	for (int i = 0, x, y, z; i<12; i += 3) {

		x = c[i + 0] - '0';
		y = c[i + 1] - '0';
		z = c[i + 2] - '0';

		mesh.addColor(ofFloatColor(x, y, z));
		mesh.addVertex(ofVec3f(x * 2 - 1, y * 2 - 1, z * 2 - 1));
	}

	vbo.setMesh(mesh, GL_STATIC_DRAW);
	Setup();
}
void Tetrahedron::Draw() {
	ofPushMatrix();
	ofScale(100, 100, 100);
	vbo.draw(GL_TRIANGLE_STRIP, 0, 24);
	ofPopMatrix();
}
void Tetrahedron::Setup() { Draw(); }
void Tetrahedron::Update() {
	Base3DObject::Update();
}