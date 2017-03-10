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
}

void ModelObj::Load()
{
	modele = new ofxAssimpModelLoader();

	modele->loadModel(filepath);
	Setup();
}
void ModelObj::Setup() {
	modele->setPosition(0,0, 0);
	modele->setRotation(2, 180, 0, 0, 1);
	modele->setScale(0.6, 0.6, 0.6);
}
void ModelObj::Draw() {

	modele->drawFaces();

}
void ModelObj::Update()
{
	modele->update();
}