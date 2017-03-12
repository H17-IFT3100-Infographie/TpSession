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
// Fonction permettant l'initialisation des param�tres de la primitive 
void Primitive::Setup()
{
}
// Fonction permettant la mise � jour des param�tres de la primitive
void Primitive::Update()
{
}
// Fonction permettant la gestion de param�tres avant rendu graphique
void Primitive::PreDraw()
{
	// D�termination si remplissage ou non
	if (fill)
		ofFill();
	else
		ofNoFill();
	// D�termination de la couleur et de la largeur du trait
	ofSetColor(color);
	ofSetLineWidth(stroke);
}
// Fonction permettant le rendu graphique de la primitive (g�r� par les classes filles)
void Primitive::Draw()
{
	
}
// Fonction permettant de r�tablir certains param�tres � leur �tat initial pour le prochain dessin
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