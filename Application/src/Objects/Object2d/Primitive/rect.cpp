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

	ofPushMatrix();
	// Déplacement au centre du rectangle
	ofTranslate(pos.x + width * 0.5f, pos.y + height * 0.5f, 0);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);	
	// Rendu du rectangle
	//ofDrawRectangle(-width * 0.5f, -height * 0.5f, width * scale.x, height * scale.y);
	ofDrawRectangle(-width * 0.5f, -height * 0.5f, width, height);
	ofPopMatrix();

	PostDraw();
}
// Fonction permettant de déterminer les frontières d'un rectangle
void Rect::DrawBoundingBox()
{
	// Paramétrage de la boîte contour
	ofSetColor(ofColor::green);
	ofNoFill();
	ofSetLineWidth(1.0f);

	ofPushMatrix();
	// Déplacement au centre du rectangle
	ofTranslate(pos.x + width * 0.5f, pos.y + height * 0.5f, 0);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	// Déplacement a l'origine (bl) du rectangle
	// Rendu de la boîte contour
	ofDrawRectangle(-width * 0.5f, -height * 0.5f, width, height);
	ofPopMatrix();

	ofSetColor(ofColor::white);
}
// Détermination de la collision entre le clic de la souris et le rectangle
bool Rect::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	// Validation des coordonnées en x et y 
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - (height * 0.5f) &&
		   mouse.x <= objScreenPos.x + (width * 0.5f) && mouse.y <= objScreenPos.y;
}
