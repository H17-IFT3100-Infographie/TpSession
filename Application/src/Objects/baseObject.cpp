#include "baseObject.h"
// Constructeur de la classe BaseObject avec 4 paramètres
BaseObject::BaseObject(float x, float y, float z, ofColor color)
	: pos(ofVec3f(x, y, z))
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
	, color(color)
{
}
// Constructeur de la classe BaseObject avec 2 paramètres
BaseObject::BaseObject(const ofVec3f& pos, ofColor color)
	: pos(pos)
	, rot(ofVec3f::one())
	, scale(ofVec3f::one())
	, color(color)
{

}
// Destructeur de la classe BaseObject
BaseObject::~BaseObject()
{
}
// Fonction d'initialisation de la classe BaseObject
void BaseObject::Setup()
{

}
// Fonction de mise à jour de la classe BaseObject
void BaseObject::Update()
{
	ClampRotation();
}
// Fonction de dessin de la classe BaseObject (La plupart de ces fonctions sont implémentées au niveau des classes filles)
void BaseObject::Draw()
{
}
// Application d'un modulo sur les valeurs de rotation
void BaseObject::ClampRotation()
{
	if (rot.x > 359.0f)
		rot.x = rot.x - 360.0f;
	else if (rot.x < 0.0f)
		rot.x = 359.0f;

	if (rot.y > 359.0f)
		rot.y = rot.y - 360.0f;
	else if (rot.y < 0.0f)
		rot.y = 359.0f;

	if (rot.z > 359.0f)
		rot.z = rot.z - 360.0f;
	else if (rot.z < 0.0f)
		rot.z = 359.0f;
}