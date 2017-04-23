#include "surface.h"

#include "../../application.h"

// Constructeur de la classe Image avec chemin de fichier en paramètre
Surface::Surface()
	: BaseObject(0.0f, 0.0f, 0.0f)
{
	Load();
	
}
// Constructeur de la classe Image avec 3 positions et un chemin de fichier en paramètres
Surface::Surface(float x, float y, float z)
	: BaseObject(x, y, z)
{
	Load();
}
// Destructeur de la classe Image
Surface::~Surface()
{

}
// Fonction permettant de charger une image
void Surface::Load()
{
	// Initialisation de l'image
	Setup();
}
// Fonction permettant l'initialisation de paramètres de l'image
void Surface::Setup()
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

void Surface::reset()
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
	// Ajout de points de contrôles
	listCrtlPoints.push_back(new Sphere(initialPosition1.x, initialPosition1.y, initialPosition1.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition2.x, initialPosition2.y, initialPosition2.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition4.x, initialPosition4.y, initialPosition4.z, radius));
	listCrtlPoints.push_back(new Sphere(initialPosition5.x, initialPosition5.y, initialPosition5.z, radius));
	listCrtlPoints.push_back(new Sphere(0.0f, 0.0f, 0.0f, radius));

	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[0]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[1]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[2]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[3]);
	Application::getInstance().getRenderer()->AddObjectInList(listCrtlPoints[4]);

	xDelta = motionSpeed;
	yDelta = motionSpeed;

	ofLog() << "<reset>";
}

// Fonction permettant la mise à jour des paramètres de l'image
void Surface::Update()
{
	UpdateSurfaces();
}
// Fonction permettant le rendu graphique de l'image
void Surface::Draw()
{
	ofPushMatrix();

		// dessiner les points de contrôle
		ofSetColor(255, 0, 0);

		listCrtlPoints[0]->Draw();
		listCrtlPoints[1]->Draw();
		listCrtlPoints[2]->Draw();
		listCrtlPoints[3]->Draw();
		listCrtlPoints[4]->Draw();

		for (int i = 0, count = triangles.size(); i < count; i++)
		{
			triangles[i].draw();
		}
		
	ofPopMatrix();
}
// Fonction permettant de déterminer les frontières d'une image
void Surface::DrawBoundingBox()
{
	listCrtlPoints[0]->DrawBoundingBox();
	listCrtlPoints[1]->DrawBoundingBox();
	listCrtlPoints[2]->DrawBoundingBox();
	listCrtlPoints[3]->DrawBoundingBox();
	listCrtlPoints[4]->DrawBoundingBox();
}
// Fonction permettant d'ajuster la teinte des pixels de l'image
void Surface::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
}
// Fonction permettant d'ajuster la composante de transparence de l'image
void Surface::SetAlpha(int a)
{

}
// Détermination de la collision entre le clic de la souris et l'image 
bool Surface::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

void Surface::ReplaceLastNodeBy(Sphere* byNode)
{
	if (nullptr != listCrtlPoints[listCrtlPoints.size() - 1])
	{
		Application::getInstance().getRenderer()->RemoveObjectInList(listCrtlPoints[listCrtlPoints.size() - 1]);
	}

	Application::getInstance().getRenderer()->AddObjectInList(byNode);
	listCrtlPoints[listCrtlPoints.size() - 1] = byNode;
	listCrtlPoints[listCrtlPoints.size() - 1]->pos = ofVec3f::zero();
}

void Surface::UpdateSurfaces()
{
	triangles.clear();

	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

	// Triangle 1
	ofVec3f top(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z);
	ofVec3f left(listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z);
	ofVec3f right(listCrtlPoints[4]->pos.x, listCrtlPoints[4]->pos.y, listCrtlPoints[4]->pos.z);
	mesh.addVertex(top);
	mesh.addVertex(left);
	mesh.addVertex(right);
	triangles.push_back(mesh);

	// Triangle 2
	mesh.clear();
	top = ofVec3f(listCrtlPoints[1]->pos.x, listCrtlPoints[1]->pos.y, listCrtlPoints[1]->pos.z);
	left = ofVec3f(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z);
	right = ofVec3f(listCrtlPoints[4]->pos.x, listCrtlPoints[4]->pos.y, listCrtlPoints[4]->pos.z);
	mesh.addVertex(top);
	mesh.addVertex(left);
	mesh.addVertex(right);
	triangles.push_back(mesh);

	// Triangle 3
	mesh.clear();
	top = ofVec3f(listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z);
	left = ofVec3f(listCrtlPoints[2]->pos.x, listCrtlPoints[2]->pos.y, listCrtlPoints[2]->pos.z);
	right = ofVec3f(listCrtlPoints[4]->pos.x, listCrtlPoints[4]->pos.y, listCrtlPoints[4]->pos.z);
	mesh.addVertex(top);
	mesh.addVertex(left);
	mesh.addVertex(right);
	triangles.push_back(mesh);

	// Triangle 4
	mesh.clear();
	top = ofVec3f(listCrtlPoints[3]->pos.x, listCrtlPoints[3]->pos.y, listCrtlPoints[3]->pos.z);
	left = ofVec3f(listCrtlPoints[0]->pos.x, listCrtlPoints[0]->pos.y, listCrtlPoints[0]->pos.z);
	right = ofVec3f(listCrtlPoints[4]->pos.x, listCrtlPoints[4]->pos.y, listCrtlPoints[4]->pos.z);
	mesh.addVertex(top);
	mesh.addVertex(left);
	mesh.addVertex(right);
	triangles.push_back(mesh);
}