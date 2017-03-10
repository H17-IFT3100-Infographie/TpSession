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
Tetrahedron(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
{
	Load();
}
void Tetrahedron::Load()
{
	mesh = new ofMesh();
	/*mesh.addVertex(ofPoint(x1, y1, 0));
	mesh.addColor(ofFloatColor(255, 0, 0));
	mesh.addVertex(ofPoint(x2, y2, 0));
	mesh.addColor(ofFloatColor(0,255, 0));
	mesh.addVertex(ofPoint(x3, y3, 0));

	mesh.addColor(ofFloatColor(0, 0, 255));
	mesh.addVertex(ofPoint(x4, y4, 0));
	mesh.addColor(ofFloatColor(255, 255, 255));*/
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			mesh.addVertex(ofPoint(x, y, 0)); // make a new vertex
			mesh.addColor(ofFloatColor(0, 0, 0));  // add a color at that vertex
		}*/
	}// now it's important to make sure that each vertex is correctly connected with the
// other vertices around it. This is done using indices, which you can set up like so:
	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {
			mesh.addIndex(x + y*width);               // 0
			mesh.addIndex((x + 1) + y*width);           // 1
			mesh.addIndex(x + (y + 1)*width);           // 10

			mesh.addIndex((x + 1) + y*width);           // 1
			mesh.addIndex((x + 1) + (y + 1)*width);       // 11
			mesh.addIndex(x + (y + 1)*width);           // 10
		}
	}
	Setup();
}
void Draw() {
	mesh.draw();
}
void Setup() { Draw(); }
void Update(){
	Base3DObject::Update();
}