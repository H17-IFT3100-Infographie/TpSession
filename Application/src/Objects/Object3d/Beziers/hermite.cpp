#include "hermite.h"

#include "../../application.h"

// Constructeur de la classe Image avec chemin de fichier en param�tre
Hermite::Hermite()
	: BaseObject(0.0f, 0.0f, 0.0f)
{
	Load();
	
}
// Constructeur de la classe Image avec 3 positions et un chemin de fichier en param�tres
Hermite::Hermite(float x, float y, float z)
	: BaseObject(x, y, z)
{
	Load();
}
// Destructeur de la classe Image
Hermite::~Hermite()
{

}
// Fonction permettant de charger une image
void Hermite::Load()
{
	// Initialisation de l'image
	Setup();
}
// Fonction permettant l'initialisation de param�tres de l'image
void Hermite::Setup()
{
	ofSetFrameRate(60);
	ofSetSphereResolution(32);
	ofDisableDepthTest();

	// param�tres
	lineResolution = 100;

	radius = 32.0f;
	scale = 10.0f;
	offset = 64.0f;

	lineWidthOutline = 4.0f;
	lineWidthCurve = 8.0f;

	motionSpeed = 250.0f;

	// initialisation des sommets de la ligne
	for (index = 0; index <= lineResolution; ++index)
		lineRenderer.addVertex(ofPoint());

	// initialisation de la sc�ne
	reset();
}

void Hermite::reset()
{
	// initialisation des variables
	framebufferWidth = ofGetWidth();
	framebufferHeight = ofGetHeight();

	// ratios de positionnement dans la fen�tre
	float w_1_8 = framebufferWidth / 8.0f - framebufferWidth * 0.5f;
	float w_1_4 = framebufferWidth / 4.0f - framebufferWidth * 0.5f;
	float w_1_2 = framebufferWidth / 2.0f - framebufferWidth * 0.5f;
	float w_3_4 = framebufferWidth * 3.0f / 4.0f - framebufferWidth * 0.5f;
	float w_7_8 = framebufferWidth * 7.0f / 8.0f - framebufferWidth * 0.5f;
	float h_1_5 = framebufferHeight / 5.0f - framebufferHeight * 0.5f;
	float h_1_3 = framebufferHeight / 3.0f - framebufferHeight * 0.5f;
	float h_4_5 = framebufferHeight * 4.0f / 5.0f - framebufferHeight * 0.5f;

	initialPosition1 = { w_1_8, h_4_5, 0 };
	initialPosition2 = { w_1_4, h_1_3, 0 };
	initialPosition3 = { w_1_2, h_1_5, 0 };
	initialPosition4 = { w_3_4, h_1_3, 0 };
	initialPosition5 = { w_7_8, h_4_5, 0 };

	listCrtlPoints.push_back(new Sphere(initialPosition1.x, initialPosition1.y, initialPosition1.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition2.x, initialPosition2.y, initialPosition2.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition4.x, initialPosition4.y, initialPosition4.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition5.x, initialPosition5.y, initialPosition5.z, radius));

	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[0]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[1]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[2]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[3]);

	xDelta = motionSpeed;
	yDelta = motionSpeed;

	ofLog() << "<reset>";
}

// Fonction permettant la mise � jour des param�tres de l'image
void Hermite::Update()
{
	ofVec3f tangent1 = listCrtlPoints[1]->pos - listCrtlPoints[0]->pos;
	ofVec3f tangent2 = listCrtlPoints[2]->pos - listCrtlPoints[3]->pos;

	for (index = 0; index <= lineResolution; ++index)
	{
		hermite(
			index / (float)lineResolution,
			listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z,
			tangent1.x, tangent1.y, tangent1.z,
			tangent2.x, tangent2.y, tangent2.z,
			listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z,
			position.x, position.y, position.z);

		// affecter la position du point sur la courbe
		lineRenderer[index] = position;
	}


}
// Fonction permettant le rendu graphique de l'image
void Hermite::Draw()
{
	ofPushMatrix();

		// dessiner la ligne contour
		ofSetColor(0, 0, 255);
		ofSetLineWidth(lineWidthOutline);

		ofDrawLine(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z, listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z);
		ofDrawLine(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z, listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z);

		// dessiner la courbe
		ofSetColor(0, 255, 0);
		ofSetLineWidth(lineWidthCurve);

		lineRenderer.draw();

		// dessiner les points de contr�le
		ofSetColor(255, 0, 0);

		listCrtlPoints[0]->Draw();
		listCrtlPoints[1]->Draw();
		listCrtlPoints[2]->Draw();
		listCrtlPoints[3]->Draw();

	ofPopMatrix();
}
// Fonction permettant de d�terminer les fronti�res d'une image
void Hermite::DrawBoundingBox()
{
	listCrtlPoints[0]->DrawBoundingBox();
	listCrtlPoints[1]->DrawBoundingBox();
	listCrtlPoints[2]->DrawBoundingBox();
}
// Fonction permettant d'ajuster la teinte des pixels de l'image
void Hermite::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
}
// Fonction permettant d'ajuster la composante de transparence de l'image
void Hermite::SetAlpha(int a)
{

}
// D�termination de la collision entre le clic de la souris et l'image 
bool Hermite::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}
