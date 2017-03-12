#include "modelObj.h"
// Constructeur de la classe ModelObj sans param�tre
ModelObj::ModelObj()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}
// Constructeur de la classe ModelObj avec le chemin du fichier. Initialisation de param�tres.
ModelObj::ModelObj(const std::string filepath) : Base3DObject(0.0f,0.0f,0.0f),filepath(filepath) {
	Load();
} 

// Destructeur de la classe ModelObj
ModelObj::~ModelObj()
{
	if (nullptr != modele)
	{
		// Destruction du mod�le et r�initialisation du pointeur
		delete modele;
		modele = nullptr;
	}

	if (nullptr != boundingBox)
	{
		delete boundingBox;
		boundingBox = nullptr;
	}
}
// Fonction permettant le chargement d'un nouveau mod�le format obj ou 3ds
void ModelObj::Load()
{
	// On g�n�re un identifiant pour le mod�le
	modele = new ofxAssimpModelLoader();
	// On r�cup�re et initialise le mod�le dont le nom de fichier est connu
	modele->loadModel(filepath);
	Setup();

	dimension = ofVec3f(100.0f, 300.0f, 100.0f);
	boundingBox = new Box(0.0f, 0.0f, 0.0f, dimension.x, dimension.y, dimension.z);
}
// Fonction permettant l'initialisation de certains param�tres propres au mod�le
void ModelObj::Setup() {
	// Gestion de la rotation du mod�le
	nextRotation = ofVec3f::zero();
	currentRotation = rot;
}
// Fonction permettant le rendu du mod�le apr�s transformations dans l'espace
void ModelObj::Draw() {
	// Initialisation de param�tres
	ofSetColor(color);

	ofPushMatrix();
	ofTranslate(pos.x, pos.y - dimension.y * 0.5f, pos.z - dimension.z * 0.5f);
	ofScale(scale);
	ofRotateX(rot.x + 180.0f);
	ofRotateY(rot.y + 180.0f);
	ofRotateZ(rot.z);
	modele->setPosition(0.0f, 0.0f, 0.0f);
	ofTranslate(0.0f, dimension.y * 0.5f, dimension.z * 0.5f);
	// Rendu graphique du mesh du mod�le
	modele->draw(ofPolyRenderMode::OF_MESH_FILL);
	ofPopMatrix(); 

	ofSetColor(ofColor::white);
}
// Fonction permettant de d�terminer les fronti�res du mod�le charg�
void ModelObj::DrawBoundingBox()
{
	ofPushMatrix();
	ofTranslate(pos.x, pos.y - dimension.y * 0.5f, pos.z + dimension.z * 0.5f);
	ofScale(scale);
	ofRotateX(rot.x + 180.0f);
	ofRotateY(rot.y + 180.0f);
	ofRotateZ(rot.z);
	boundingBox->DrawBoundingBox();
	ofPopMatrix();
}
// Fonction permettant la mise � jour des param�tres du mod�le
void ModelObj::Update()
{
	Base3DObject::Update();
	// Mise � jour de la rotation du mod�le 
	if (currentRotation != rot)
	{
		nextRotation += currentRotation - rot;
		currentRotation = rot;
	}
	modele->update();
}
// Fonction permettant de d�terminer s'il y a collision entre le clic de la souris et le mod�le
bool ModelObj::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x > objScreenPos.x - (dimension.x * 0.5f) * scale.x && mouse.y > objScreenPos.y &&
		mouse.x <= objScreenPos.x + (dimension.x * 0.5f) * scale.x && mouse.y <= objScreenPos.y + (dimension.y * 0.5f) * scale.y;
}