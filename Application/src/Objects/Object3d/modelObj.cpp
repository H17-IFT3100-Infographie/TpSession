#include "modelObj.h"

ModelObj::ModelObj()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}
ModelObj::ModelObj(const std::string filepath) : Base3DObject(0.0f,0.0f,0.0f),filepath(filepath) {
	Load();
} 
ModelObj::ModelObj(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}

ModelObj::~ModelObj()
{
	if (nullptr != modele)
	{
		delete modele;
		modele = nullptr;
	}
}

void ModelObj::Load()
{
	modele = new ofxAssimpModelLoader();

	modele->loadModel(filepath);
	Setup();
}
void ModelObj::Setup() {
	nextRotation = ofVec3f::zero();
	currentRotation = rot;
}
void ModelObj::Draw() {
	ofSetColor(color);

	modele->setPosition(pos.x, pos.y, pos.z);

    modele->setRotation(0, rot.x, 1, 0, 0);
	modele->setRotation(1, rot.y, 0, 1, 0);
	modele->setRotation(2, rot.z, 0, 0, 1);

	modele->setScale(scale.z, scale.y, scale.z);

	modele->draw(ofPolyRenderMode::OF_MESH_FILL);

	ofSetColor(ofColor::white);
}
void ModelObj::Update()
{
	Base3DObject::Update();

	if (currentRotation != rot)
	{
		nextRotation += currentRotation - rot;
		currentRotation = rot;
	}
	modele->update();
}