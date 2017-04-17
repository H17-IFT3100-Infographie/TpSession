#include "cubic.h"

#include "../../application.h"

// Constructeur de la classe Image avec chemin de fichier en paramètre
Cubic::Cubic(bool drawSurface)
	: BaseObject(0.0f, 0.0f, 0.0f)
	, drawSurface(drawSurface)
{
	Load();
	
}
// Constructeur de la classe Image avec 3 positions et un chemin de fichier en paramètres
Cubic::Cubic(float x, float y, float z, bool drawSurface)
	: BaseObject(x, y, z)
	, drawSurface(drawSurface)
{
	Load();
}
// Destructeur de la classe Image
Cubic::~Cubic()
{

}
// Fonction permettant de charger une image
void Cubic::Load()
{
	// Initialisation de l'image
	Setup();
}
// Fonction permettant l'initialisation de paramètres de l'image
void Cubic::Setup()
{
	ofSetFrameRate(60);
	ofSetSphereResolution(32);
	ofDisableDepthTest();

	// paramètres
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

	// initialisation de la scène
	reset();
}

void Cubic::reset()
{
	// initialisation des variables
	framebufferWidth = ofGetWidth();
	framebufferHeight = ofGetHeight();

	// ratios de positionnement dans la fenêtre
	float w_1_8 = pos.x + framebufferWidth / 8.0f - framebufferWidth * 0.5f;
	float w_1_4 = pos.x + framebufferWidth / 4.0f - framebufferWidth * 0.5f;
	float w_1_2 = pos.x + framebufferWidth / 2.0f - framebufferWidth * 0.5f;
	float w_3_4 = pos.x + framebufferWidth * 3.0f / 4.0f - framebufferWidth * 0.5f;
	float w_7_8 = pos.x + framebufferWidth * 7.0f / 8.0f - framebufferWidth * 0.5f;
	float h_1_5 = pos.y + framebufferHeight / 5.0f - framebufferHeight * 0.5f;
	float h_1_3 = pos.y + framebufferHeight / 3.0f - framebufferHeight * 0.5f;
	float h_4_5 = pos.y + framebufferHeight * 4.0f / 5.0f - framebufferHeight * 0.5f;

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

// Fonction permettant la mise à jour des paramètres de l'image
void Cubic::Update()
{
	for (index = 0; index <= lineResolution; ++index)
	{
		bezierCubic(
			index / (float)lineResolution,
			listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z,
			listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z,
			listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z,
			listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z,
			position.x, position.y, position.z);

		// affecter la position du point sur la courbe
		lineRenderer[index] = position;
	}


}
// Fonction permettant le rendu graphique de l'image
void Cubic::Draw()
{
	ofPushMatrix();

		// dessiner la ligne contour
		ofSetColor(0, 0, 255);
		ofSetLineWidth(lineWidthOutline);

		ofDrawLine(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z, listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z);
		ofDrawLine(listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z, listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z);
		ofDrawLine(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z, listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z);
		ofDrawLine(listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z, listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z);

		// dessiner la courbe
		ofSetColor(0, 255, 0);
		ofSetLineWidth(lineWidthCurve);

		lineRenderer.draw();

		// dessiner les points de contrôle
		ofSetColor(255, 0, 0);

		listCrtlPoints[0]->Draw();
		listCrtlPoints[1]->Draw();
		listCrtlPoints[2]->Draw();
		listCrtlPoints[3]->Draw();

		if (drawSurface)
		{
			CreateSurfaces();
			triangle1.draw();
			triangle2.draw();
		}
		
	ofPopMatrix();
}
// Fonction permettant de déterminer les frontières d'une image
void Cubic::DrawBoundingBox()
{
	listCrtlPoints[0]->DrawBoundingBox();
	listCrtlPoints[1]->DrawBoundingBox();
	listCrtlPoints[2]->DrawBoundingBox();
	listCrtlPoints[3]->DrawBoundingBox();
}
// Fonction permettant d'ajuster la teinte des pixels de l'image
void Cubic::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
}
// Fonction permettant d'ajuster la composante de transparence de l'image
void Cubic::SetAlpha(int a)
{

}
// Détermination de la collision entre le clic de la souris et l'image 
bool Cubic::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

void Cubic::ReplaceLastNodeBy(Sphere* byNode)
{
	if (nullptr != listCrtlPoints[listCrtlPoints.size() - 1])
	{
		Application::getInstance().getRenderer()->RemoveObjectInList(listCrtlPoints[listCrtlPoints.size() - 1]);
	}

	Application::getInstance().getRenderer()->AddObjectInList(byNode);
	listCrtlPoints[listCrtlPoints.size() - 1] = byNode;
	listCrtlPoints[listCrtlPoints.size() - 1]->pos = ofVec3f::zero();
}

void Cubic::CreateSurfaces()
{
	triangle1.clear();

	triangle1.setMode(OF_PRIMITIVE_TRIANGLES);

	ofVec3f top(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z);
	ofVec3f left(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z);
	ofVec3f right(listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z);
	
	triangle1.addVertex(top);
	triangle1.addVertex(left);
	triangle1.addVertex(right);

	triangle2.clear();

	triangle2.setMode(OF_PRIMITIVE_TRIANGLES);

	top = ofVec3f(listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z);
	left = ofVec3f(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z);
	right = ofVec3f(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z);

	triangle2.addVertex(top);
	triangle2.addVertex(left);
	triangle2.addVertex(right);
}