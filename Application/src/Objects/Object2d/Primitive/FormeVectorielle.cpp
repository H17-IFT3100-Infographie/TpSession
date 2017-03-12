#include "FormeVectorielle.h"
// Constructeur de la classe FormeVectorielle 5 param�tres et initialisation
FormeVectorielle::FormeVectorielle(ofPoint center, float radius, float stroke, bool fill, ofColor color)
	: Primitive(center, stroke, fill, color)
	, radius(radius){
}

// Destructeur de la classe FormeVectorielle
FormeVectorielle::~FormeVectorielle()
{
}
// Fonction permettant l'initialisation des param�tres d'un cercle
void FormeVectorielle::Setup()
{
}
// Fonction permettant la mise � jour des param�tres d'un cercle
void FormeVectorielle::Update()
{
}
// Fonction permettant le rendu d'un cercle
void FormeVectorielle::Draw()
{
	PreDraw();
	// Dessin de 5 cercles concentriques
	ofDrawCircle(pos, radius);

	ofDrawCircle(pos, radius + 20);

	ofDrawCircle(pos, radius + 50);

	ofDrawCircle(pos, radius + 100);

	ofDrawCircle(pos, radius + 200);

	PostDraw();
}

// Fonction permettant de d�limiter les fronti�res du cercle par un rectangle
void FormeVectorielle::DrawBoundingBox()
{
	// On d�terminer la couleur de la limite de l'objet
	ofSetColor(ofColor::green);
	// On initialise certains param�tres au go�t
	ofNoFill();
	ofSetLineWidth(1.0f);
	// Dessin du rectangle englobant le cercle
	ofDrawRectangle(pos.x - radius - 200, pos.y - radius - 200, (radius+200) * 2.0f, (radius +200) * 2.0f);

	ofSetColor(ofColor::white);
}
// Fonction permettant de modifier la transparence du cercle
void FormeVectorielle::SetAlpha(int a)
{
}
// Fonction permettant de d�terminer s'il y a collision entre la souris et la figure g�om�trique
bool FormeVectorielle::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - ((radius + 200) * 0.5f) * scale.x && mouse.y >= objScreenPos.y - ((radius + 200) * 0.5f) * scale.y &&
		mouse.x <= objScreenPos.x + ((radius +200) * 0.5f) * scale.x && mouse.y <= objScreenPos.y + ((radius + 200) * 0.5f) * scale.y;
}