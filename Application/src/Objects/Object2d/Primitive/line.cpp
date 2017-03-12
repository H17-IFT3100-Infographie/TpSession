#include "line.h"
// Constructeur de la primitive vectorielle ligne avec 4 paramètres
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
// Fonction permettant la mise à jour de la classe line
void Line::Update()
{
}
// Fonction permettant le rendu d'une line
void Line::Draw()
{
	PreDraw();

	ofPushMatrix();
	ofTranslate(pos.x + endPoint.x * 0.5f, pos.y + endPoint.y * 0.5f, pos.z + endPoint.z * 0.5f);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofTranslate(-endPoint.x * 0.5f, -endPoint.y * 0.5f, -endPoint.z * 0.5f);
	// Dessin d'une ligne avec une position de départ et une position d'arrivée
	ofDrawLine(ofPoint(0.0f, 0.0f, 0.0f), endPoint);
	ofPopMatrix();

	PostDraw();
}
// Détermination des frontières englobant la ligne.
void Line::DrawBoundingBox()
{
	// Détermination des paramètres pour le dessin de la boîte de contour
	ofSetColor(ofColor::green);

	ofNoFill();
	ofSetLineWidth(1.0f);

	ofPushMatrix();
	ofTranslate(pos.x + endPoint.x * 0.5f, pos.y + endPoint.y * 0.5f, pos.z + endPoint.z * 0.5f);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofTranslate(-endPoint.x * 0.5f, -endPoint.y * 0.5f, -endPoint.z * 0.5f);
	// Dessin du rectangle englobant la ligne
	ofDrawRectangle(0.0f, 0.0f, endPoint.x, endPoint.y);
	ofPopMatrix();

	ofSetColor(ofColor::white);
}
// Fonction permettant de déterminer la valeur de transparence de la ligne
void Line::SetAlpha(int a)
{

}
// Fonction permettant de valider s'il y a une collision entre une ligne et la souris
bool Line::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.y >= objScreenPos.y - endPoint.y * 0.5f * scale.y && mouse.y <= objScreenPos.y
		&& mouse.x >= objScreenPos.x && mouse.x <= objScreenPos.x + endPoint.x * 0.5f * scale.x;
}