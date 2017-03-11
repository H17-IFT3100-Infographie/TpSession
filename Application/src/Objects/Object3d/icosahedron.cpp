#include "Icosahedron.h"

Icosahedron::Icosahedron()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}

Icosahedron::Icosahedron(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}

Icosahedron::~Icosahedron()
{
}
Icosahedron::Icosahedron(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
	: Base3DObject(x1, y1, 0)
{
	Load();
}

void Icosahedron::Load()
{
	ofMesh mesh; 
	
	radius = 50.0f;

	Setup();
}

void Icosahedron::Draw() {
	
	for (int i = 0; i < mesh.getNumVertices(); i++)
	{
		mesh.setColor(i, color);
	}

	ofPushMatrix();
	ofTranslate(pos);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofScale(scale);
	mesh.drawFaces();
	ofPopMatrix();
}

void Icosahedron::DrawBoundingBox()
{
	for (int i = 0; i < mesh.getNumVertices(); i++)
	{
		mesh.setColor(i, ofColor::green);
	}

	ofPushMatrix();
	ofTranslate(pos);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofScale(scale);
	mesh.drawWireframe();
	ofPopMatrix();
}

bool Icosahedron::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y &&
		mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}

void Icosahedron::Setup()
{
	mesh.clear();

	float t = ((1 + sqrt(5)) / 2) * radius;
	mesh.addVertex(ofVec3f(t, 1, 0)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-t, 1, 0));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(t, -1, 0));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-t, -1, 0)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f( 1,0,t)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(1,0,-t));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-1,0,t)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-1,0,-t));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,t,1)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,-t,1)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0, t,-1));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,-t,-1)); 
	mesh.addColor(color);

	int indices[20][3] = { {0,8,4},{0,5,10},{2,4,9},{2,11,5},{1,6,8},{1,10,7},{3,9,6},{3,7,11},{0,10,8},{1,8,10},{2,9,11},{3,9,11},{4,2,0},{5,0,2},{6,1,3},{7,3,4},{8,6,4},{9,4,6},{10,5,7},{11,7,5} };

	for (int i = 0; i < 20; i++) {
		mesh.addIndex(indices[i][0]);
		mesh.addIndex(indices[i][1]);
		mesh.addIndex(indices[i][2]);

	}
}
