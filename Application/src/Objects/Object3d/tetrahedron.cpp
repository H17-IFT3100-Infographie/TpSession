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
Tetrahedron::Tetrahedron(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
	: Base3DObject(x1, y1, 0)
{
	Load();
}

void Tetrahedron::Load()
{
	ofMesh mesh; 
	
	/*
		mesh.addColor(ofColor(255, 0, 0));
		mesh.addVertex(ofVec3f(0, 0, 1)); 
		mesh.addColor(ofColor(255, 255, 0));
		mesh.addVertex(ofVec3f(0,2*sqrt(2),-1)/3);
		mesh.addColor(ofColor(255, 0, 255));
		mesh.addVertex(ofVec3f(-sqrt(6),-sqrt(2),-1)/3);
		mesh.addColor(ofColor(0, 0, 0));
		mesh.addVertex(ofVec3f(sqrt(6),-sqrt(2),-1)/3);
*/
		Setup();
}

void Tetrahedron::Draw() {
	ofPushMatrix();
	ofScale(50, 50, 50);
	mesh.drawFaces();
	ofPopMatrix();
}

void Tetrahedron::DrawBoundingBox()
{

}

void Tetrahedron::Setup()
{
	float t = (1 + sqrt(5)) / 2;
	mesh.addVertex(ofVec3f(t, 1, 0)); mesh.addColor(ofColor(255, 0, 0));
	mesh.addVertex(ofVec3f(-t, 1, 0)); mesh.addColor(ofColor(255,255, 0));
	mesh.addVertex(ofVec3f(t, -1, 0)); mesh.addColor(ofColor(255, 0, 255));
	mesh.addVertex(ofVec3f(-t, -1, 0)); mesh.addColor(ofColor(255, 0, 0));
	mesh.addVertex(ofVec3f( 1,0,t)); mesh.addColor(ofColor(200, 0, 0));
	mesh.addVertex(ofVec3f(1,0,-t)); mesh.addColor(ofColor(200, 200, 0));
	mesh.addVertex(ofVec3f(-1,0,t)); mesh.addColor(ofColor(200, 0, 200));
	mesh.addVertex(ofVec3f(-1,0,-t)); mesh.addColor(ofColor(150, 0, 0));
	mesh.addVertex(ofVec3f(0,t,1)); mesh.addColor(ofColor(150, 150, 0));
	mesh.addVertex(ofVec3f(0,-t,1)); mesh.addColor(ofColor(150, 0, 150));
	mesh.addVertex(ofVec3f(0, t,-1)); mesh.addColor(ofColor(255, 255, 255));
	mesh.addVertex(ofVec3f(0,-t,-1)); mesh.addColor(ofColor(0, 0, 0));
	float hue = 254.f;
	int indices[20][3] = { {0,8,4},{0,5,10},{2,4,9},{2,11,5},{1,6,8},{1,10,7},{3,9,6},{3,7,11},{0,10,8},{1,8,10},{2,9,11},{3,9,11},{4,2,0},{5,0,2},{6,1,3},{7,3,4},{8,6,4},{9,4,6},{10,5,7},{11,7,5} };

	for (int i = 0; i < 20; i++) {
		mesh.addIndex(indices[i][0]);
		mesh.addIndex(indices[i][1]);
		mesh.addIndex(indices[i][2]);

	}Draw();
}