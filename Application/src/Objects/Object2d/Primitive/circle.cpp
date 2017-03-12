#include "circle.h"
// Constructeur avec 5 paramètres de la classe cercle, avec paramètres d'initialisation
Circle::Circle(ofPoint center, float radius, float stroke, bool fill, ofColor color)
	: Primitive(center, stroke, fill, color)
	, radius(radius)
{

}
// Destructeur de la classe cercle
Circle::~Circle()
{

}
// Fonction permettant l'initialisation des paramètres d'un cercle
void Circle::Setup()
{
}
// Fonction permettant la mise à jour des paramètres d'un cercle
void Circle::Update()
{
}
// Fonction permettant le rendu d'un cercle
void Circle::Draw()
{
	PreDraw();

	// Dessin d'un cercle
	ofPushMatrix();
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofDrawCircle(pos, radius * scale.x);
	ofPopMatrix();

	PostDraw();
}
// Déterminer les limites du cercle
void Circle::DrawBoundingBox()
{
	// On déterminer la couleur de la limite de l'objet
	ofSetColor(ofColor::green);
	// On initialise certains paramètres au goût
	ofNoFill();
	ofSetLineWidth(1.0f);

	ofPushMatrix();
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	// Dessin du rectangle englobant le cercle
	ofDrawRectangle(pos.x - radius * scale.x, pos.y - radius * scale.x, radius * scale.x * 2.0f, radius * scale.x * 2.0f);
	ofPopMatrix();

	ofSetColor(ofColor::white);
}

// Fonction permettant de modifier la transparence du cercle
void Circle::SetAlpha(int a)
{
}

// Fonction permettant de déterminer s'il y a collision entre la souris et la figure géométrique
bool Circle::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y && 
		   mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}