#include "Base3DObject.h"
// Constructeur de la classe Base3DObject avec 3 param�tres pour la position
Base3DObject::Base3DObject(float x, float y, float z)
	: BaseObject(x, y, z)
{
}
// Constructeur de la classe Base3DObject avec 1 param�tre pour la position 
Base3DObject::Base3DObject(const ofVec3f& pos) 
	: BaseObject(pos)
{

}
// Destructeur de la classe Base3DObject
Base3DObject::~Base3DObject()
{
	if (nullptr != primitive)
	{
		// On d�truit la primitive associ�e au Base3DObject
		delete primitive;
		primitive = nullptr;
	}
}
// Fonction permettant le rendu graphique d'instances de la classe Base3DObject
void Base3DObject::Draw()
{
	// D�termination de certains param�tres et transformations
	ofSetColor(color);

	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	// Rendu graphique de la primitive associ�e au Base3DObject
	primitive->draw();

	ofSetColor(ofColor::white);
}
// Fonction permettant de d�terminer les limites d'un Base3DObject
void Base3DObject::DrawBoundingBox()
{
	// D�termination de certains param�tres pour l'affichage de la bo�te fronti�re
	ofSetColor(ofColor::green);
	
	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	// Affichage de la bo�te fronti�re
	primitive->drawWireframe();

	ofSetColor(ofColor::white);
}