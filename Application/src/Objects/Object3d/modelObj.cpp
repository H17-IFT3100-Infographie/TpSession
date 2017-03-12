#include "modelObj.h"
// Constructeur de la classe ModelObj sans paramètre
ModelObj::ModelObj()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}
// Constructeur de la classe ModelObj avec le chemin du fichier. Initialisation de paramètres.
ModelObj::ModelObj(const std::string filepath) : Base3DObject(0.0f,0.0f,0.0f),filepath(filepath) {
	Load();
} 

// Destructeur de la classe ModelObj
ModelObj::~ModelObj()
{
	if (nullptr != modele)
	{
		// Destruction du modèle et réinitialisation du pointeur
		delete modele;
		modele = nullptr;
	}
}
// Fonction permettant le chargement d'un nouveau modèle format obj ou 3ds
void ModelObj::Load()
{
	// On génère un identifiant pour le modèle
	modele = new ofxAssimpModelLoader();
	// On récupère et initialise le modèle dont le nom de fichier est connu
	modele->loadModel(filepath);
	Setup();

	dimension = ofVec3f(100.0f, 400.0f, 100.0f);
}
// Fonction permettant l'initialisation de certains paramètres propres au modèle
void ModelObj::Setup() {
	// Gestion de la rotation du modèle
	nextRotation = ofVec3f::zero();
	currentRotation = rot;
}
// Fonction permettant le rendu du modèle après transformations dans l'espace
void ModelObj::Draw() {
	// Initialisation de paramètres
	ofSetColor(color);

	modele->setPosition(pos.x, pos.y, pos.z);

    modele->setRotation(0, rot.x, 1, 0, 0);
	modele->setRotation(1, rot.y, 0, 1, 0);
	modele->setRotation(2, rot.z, 0, 0, 1);

	modele->setScale(scale.x, scale.y, scale.z);
	// Rendu graphique du mesh du modèle
	modele->draw(ofPolyRenderMode::OF_MESH_FILL);

	ofSetColor(ofColor::white);
}
// Fonction permettant de déterminer les frontières du modèle chargé
void ModelObj::DrawBoundingBox()
{
	//TODO
}
// Fonction permettant la mise à jour des paramètres du modèle
void ModelObj::Update()
{

	Base3DObject::Update();
	// Mise à jour de la rotation du modèle 
	if (currentRotation != rot)
	{
		nextRotation += currentRotation - rot;
		currentRotation = rot;
	}
	modele->update();
}
// Fonction permettant de déterminer s'il y a collision entre le clic de la souris et le modèle
bool ModelObj::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x > objScreenPos.x - (dimension.x * 0.5f) * scale.x && mouse.y > objScreenPos.y &&
		mouse.x <= objScreenPos.x + (dimension.x * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (dimension.y * 0.5f) * scale.y;
}