#include "line.h"
// Constructeur de la primitive vectorielle ligne avec 4 param�tres
Line::Line(ofPoint p1, ofPoint p2, float stroke, ofColor color)
	: Primitive(p1, stroke, color)
	, endPoint(p2)
{

}
// Destructeur de la classe line
Line::~Line()
{

}
// Fonction permettant l'initialisation de la classe line 
void Line::Setup()
{
}
// Fonction permettant la mise � jour de la classe line
void Line::Update()
{
}
// Fonction permettant le rendu d'une line
void Line::Draw()
{
	PreDraw();
	// Dessin d'une ligne avec une position de d�part et une position d'arriv�e
	ofDrawLine(pos, pos + endPoint);

	PostDraw();
}
// D�termination des fronti�res englobant la ligne.
void Line::DrawBoundingBox()
{
	// D�termination des param�tres pour le dessin de la bo�te de contour
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);
	// Dessin du rectangle englobant la ligne
	ofDrawRectangle(pos.x, pos.y, endPoint.x - pos.x, endPoint.y - pos.y);

	ofSetColor(ofColor::white);
}
// Fonction permettant de d�terminer la valeur de transparence de la ligne
void Line::SetAlpha(int a)
{

}
// Fonction permettant de valider s'il y a une collision entre une ligne et la souris
bool Line::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - endPoint.x - pos.x && mouse.x <= objScreenPos.x + endPoint.x - pos.x && mouse.y <= objScreenPos.y;
}