#include "primitive.h"
// Constructeur de la classe Primitive avec un point, une largeur de trait et une couleur
Primitive::Primitive(ofPoint pos, float stroke, ofColor color)
	: BaseObject(pos.x, pos.y, pos.z)
	, stroke(stroke)
	, fill(false)
{

}
// Constructeur de la classe Primitive avec option de remplissage 
Primitive::Primitive(ofPoint pos, float stroke, bool fill, ofColor color)
	: BaseObject(pos.x, pos.y, pos.z)
	, stroke(stroke)
	, fill(fill)
{

}
// Destructeur de la classe Primitive
Primitive::~Primitive()
{

}
// Fonction permettant l'initialisation des paramètres de la primitive 
void Primitive::Setup()
{
}
// Fonction permettant la mise à jour des paramètres de la primitive
void Primitive::Update()
{
}
// Fonction permettant la gestion de paramètres avant rendu graphique
void Primitive::PreDraw()
{
	// Détermination si remplissage ou non
	if (fill)
		ofFill();
	else
		ofNoFill();
	// Détermination de la couleur et de la largeur du trait
	ofSetColor(color);
	ofSetLineWidth(stroke);
}
// Fonction permettant le rendu graphique de la primitive (géré par les classes filles)
void Primitive::Draw()
{
	
}
// Fonction permettant de rétablir certains paramètres à leur état initial pour le prochain dessin
void Primitive::PostDraw()
{
	ofSetLineWidth(1.0f);
	ofSetColor(ofColor::white);
}

void Primitive::SetAlpha(int a)
{

}

bool Primitive::IsHovered(float x, float y)
{
	return false;
}