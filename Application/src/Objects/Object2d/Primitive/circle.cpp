#include "circle.h"
// Constructeur avec 5 param�tres de la classe cercle, avec param�tres d'initialisation
Circle::Circle(ofPoint center, float radius, float stroke, bool fill, ofColor color)
	: Primitive(center, stroke, fill, color)
	, radius(radius)
{

}
// Destructeur de la classe cercle
Circle::~Circle()
{

}
// Fonction permettant l'initialisation des param�tres d'un cercle
void Circle::Setup()
{
}
// Fonction permettant la mise � jour des param�tres d'un cercle
void Circle::Update()
{
}
// Fonction permettant le rendu d'un cercle
void Circle::Draw()
{
	PreDraw();
	// Dessin d'un cercle
	ofDrawCircle(pos, radius);
	
	PostDraw();
}
// D�terminer les limites du cercle
void Circle::DrawBoundingBox()
{
	// On d�terminer la couleur de la limite de l'objet
	ofSetColor(ofColor::green);
	// On initialise certains param�tres au go�t
	ofNoFill();
	ofSetLineWidth(1.0f);
	// Dessin du rectangle englobant le cercle
	ofDrawRectangle(pos.x - radius, pos.y - radius, radius * 2.0f, radius * 2.0f);

	ofSetColor(ofColor::white);
}

// Fonction permettant de modifier la transparence du cercle
void Circle::SetAlpha(int a)
{
}

// Fonction permettant de d�terminer s'il y a collision entre la souris et la figure g�om�trique
bool Circle::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y && 
		   mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}