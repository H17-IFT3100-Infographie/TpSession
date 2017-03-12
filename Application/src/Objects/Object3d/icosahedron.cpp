#include "Icosahedron.h"
// Constructeur de la classe Icosahedron sans paramètre
Icosahedron::Icosahedron()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}
// Constructeur de la classe icosahedron avec paramètres de position et de rayon
Icosahedron::Icosahedron(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}
// Destructeur de la classe icosahedron
Icosahedron::~Icosahedron()
{
}

// Fonction permettant de charger l'icosahèdre et d'en déterminer les paramètres
void Icosahedron::Load()
{
	// On génère le mesh qui formera l'icosahèdre
	ofMesh mesh;
	
	radius = 50.0f;
	// Préparation des paramètres de l'icosahèdre
	Setup();
}
// Fonction permettant de faire le rendu graphique de l'icosahèdre
void Icosahedron::Draw() {
	// Détermination de la couleur des sommets
	for (int i = 0; i < mesh.getNumVertices(); i++)
	{
		mesh.setColor(i, color);
	}
	// Application de transformations dans l'espace de l'icosahèdre
	ofPushMatrix();
	ofTranslate(pos);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofScale(scale);
	// Affichage du mesh
	mesh.drawFaces();
	ofPopMatrix();
}
// Détermination des limites de la boîte frontière et rendu
void Icosahedron::DrawBoundingBox()
{
	// Affocjage des sommets en vert
	for (int i = 0; i < mesh.getNumVertices(); i++)
	{
		mesh.setColor(i, ofColor::green);
	}
	// Application de transformations dans l'univers de l'icosahèdre
	ofPushMatrix();
	ofTranslate(pos);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofScale(scale);
	// Dessin du mesh présentant les arêtes en vert de l'objet sélectionné 
	mesh.drawWireframe();
	ofPopMatrix();
}
// Détermination de la collision entre le clic de la souris et l'icosahèdre
bool Icosahedron::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (radius * 0.5f) * scale.x && mouse.y >= objScreenPos.y - (radius * 0.5f) * scale.y &&
		mouse.x <= objScreenPos.x + (radius * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (radius * 0.5f) * scale.y;
}
// Fonction permettant l'initialisation des paramètres de l'icosahèdre
void Icosahedron::Setup()
{
	mesh.clear();
	float t = ((1 + sqrt(5)) / 2) * radius;
	// Génération des sommets de l'icosahèdre
	mesh.addVertex(ofVec3f(t, 1, 0));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-t, 1, 0));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(t, -1, 0));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-t, -1, 0)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f( 1,0,t)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(1,0,-t));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-1,0,t)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(-1,0,-t));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,t,1)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,-t,1)); 
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0, t,-1));
	mesh.addColor(color);

	mesh.addVertex(ofVec3f(0,-t,-1)); 
	mesh.addColor(color);
	// Tableau en 2 dimensions contenant les groupes de sommets formant des triangles
	int indices[20][3] = { {0,8,4},{0,5,10},{2,4,9},{2,11,5},{1,6,8},{1,10,7},{3,9,6},{3,7,11},{0,10,8},{1,8,10},{2,9,11},{3,9,11},{4,2,0},{5,0,2},{6,1,3},{7,3,4},{8,6,4},{9,4,6},{10,5,7},{11,7,5} };
	// Génération des index pour le rendu
	for (int i = 0; i < 20; i++) {
		mesh.addIndex(indices[i][0]);
		mesh.addIndex(indices[i][1]);
		mesh.addIndex(indices[i][2]);

	}
}
