#include "Base3DObject.h"
// Constructeur de la classe Base3DObject avec 3 paramètres pour la position
Base3DObject::Base3DObject(float x, float y, float z)
	: BaseObject(x, y, z)
{
}
// Constructeur de la classe Base3DObject avec 1 paramètre pour la position 
Base3DObject::Base3DObject(const ofVec3f& pos) 
	: BaseObject(pos)
{

}
// Destructeur de la classe Base3DObject
Base3DObject::~Base3DObject()
{
	if (nullptr != primitive)
	{
		// On détruit la primitive associée au Base3DObject
		delete primitive;
		primitive = nullptr;
	}
}
// Fonction permettant le rendu graphique d'instances de la classe Base3DObject
void Base3DObject::Draw()
{
	// Détermination de certains paramètres et transformations
	ofSetColor(color);

	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	// Rendu graphique de la primitive associée au Base3DObject
	primitive->draw();

	ofSetColor(ofColor::white);
}
// Fonction permettant de déterminer les limites d'un Base3DObject
void Base3DObject::DrawBoundingBox()
{
	// Détermination de certains paramètres pour l'affichage de la boîte frontière
	ofSetColor(ofColor::green);
	
	primitive->setScale(scale);
	primitive->setPosition(pos);
	primitive->setOrientation(rot);
	// Affichage de la boîte frontière
	primitive->drawWireframe();

	ofSetColor(ofColor::white);
}