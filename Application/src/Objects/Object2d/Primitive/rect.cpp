#include "rect.h"
// Constructeur de la classe Rect avec 6 param�tres et initialisation
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
// Fonction permettant l'initialisation des param�tres du rectangle
void Rect::Setup()
{
}
// Fonction permettant la mise � jour des param�tres du rectangle
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
// Fonction permettant de d�terminer les fronti�res d'un rectangle
void Rect::DrawBoundingBox()
{
	// Param�trage de la bo�te contour
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	// Rendu de la bo�te contour
	ofDrawRectangle(pos.x, pos.y, width, height);

	ofSetColor(ofColor::white);
}
// D�termination de la collision entre le clic de la souris et le rectangle
bool Rect::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	// Validation des coordonn�es en x et y 
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - (height * 0.5f) * scale.y &&
		   mouse.x <= objScreenPos.x + (width * 0.5f) * scale.x && mouse.y <= objScreenPos.y;
}
