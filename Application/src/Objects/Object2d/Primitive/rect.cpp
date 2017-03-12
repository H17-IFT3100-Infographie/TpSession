#include "rect.h"
// Constructeur de la classe Rect avec 6 paramètres et initialisation
Rect::Rect(ofPoint tl, float width, float height, float lineStroke, bool fill, ofColor color)
	: Primitive(tl, lineStroke, fill, color)
	, width(width)
	, height(height)
{

}
// Destructeur de la classe Rect
Rect::~Rect()
{

}
// Fonction permettant l'initialisation des paramètres du rectangle
void Rect::Setup()
{
}
// Fonction permettant la mise à jour des paramètres du rectangle
void Rect::Update()
{
}
// Fonction permettant le rendu graphique d'un rectangle
void Rect::Draw()
{
	PreDraw();
	// Rendu du rectangle
	ofDrawRectangle(pos.x, pos.y, width, height);
	
	PostDraw();
}
// Fonction permettant de déterminer les frontières d'un rectangle
void Rect::DrawBoundingBox()
{
	// Paramétrage de la boîte contour
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	// Rendu de la boîte contour
	ofDrawRectangle(pos.x, pos.y, width, height);

	ofSetColor(ofColor::white);
}
// Détermination de la collision entre le clic de la souris et le rectangle
bool Rect::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	// Validation des coordonnées en x et y 
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - (height * 0.5f) * scale.y &&
		   mouse.x <= objScreenPos.x + (width * 0.5f) * scale.x && mouse.y <= objScreenPos.y;
}
