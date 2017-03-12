#include "image.h"
// Constructeur de la classe Image avec chemin de fichier en paramètre
Image::Image(const std::string filepath)
	: BaseObject(0.0f, 0.0f, 0.0f)
	, filepath(filepath)
{
	Load();
	
}
// Constructeur de la classe Image avec 3 positions et un chemin de fichier en paramètres
Image::Image(float x, float y, float z, const std::string filepath)
	: BaseObject(x, y, z)
	, filepath(filepath)
{
	Load();
}
// Destructeur de la classe Image
Image::~Image()
{
	// Destruction de l'image et désallocation du pointeur
	delete image;
	image = nullptr;
}
// Fonction permettant de charger une image
void Image::Load()
{
	// Allocation mémoire pour le chargement de l'image
	image = new ofImage();
	// Chargement de l'image située au chemin d'accès 
	image->load(filepath);
	// Initialisation de l'image
	Setup();
}
// Fonction permettant l'initialisation de paramètres de l'image
void Image::Setup()
{
	originalDimension = ofVec3f(image->getWidth(), image->getHeight(), 0.0f);

	originalColor.clear();
	for (int i = 0; i < image->getWidth(); i++)
	{
		originalColor.push_back(std::vector<ofColor>());
		for (int j = 0; j < image->getHeight(); j++)
		{
			originalColor[i].push_back(image->getColor(i, j));
		}
	}

	boundingBox = new Rect(ofPoint(pos.x, pos.y, pos.z), image->getWidth(), image->getHeight(), 1.0f, false, ofColor::green);
}
// Fonction permettant la mise à jour des paramètres de l'image
void Image::Update()
{
	image->update();
}
// Fonction permettant le rendu graphique de l'image
void Image::Draw()
{
	ofPushMatrix();
	ofTranslate(pos.x + image->getWidth() * 0.5f, pos.y + image->getHeight() * 0.5f, pos.z);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	image->setAnchorPoint(image->getWidth() * 0.5f, image->getHeight() * 0.5f);
	image->draw(0.0f, 0.0f, 0.0f, image->getWidth(), image->getHeight());
	ofPopMatrix();
}
// Fonction permettant de déterminer les frontières d'une image
void Image::DrawBoundingBox()
{
	ofSetColor(ofColor::green);
	ofNoFill();
	ofPushMatrix();
	ofTranslate(pos.x + image->getWidth() * 0.5f, pos.y + image->getHeight() * 0.5f, pos.z);
	ofScale(scale);
	ofRotateX(rot.x);
	ofRotateY(rot.y);
	ofRotateZ(rot.z);
	ofDrawRectangle(-image->getWidth() * 0.5f, -image->getHeight() * 0.5f, image->getWidth(), image->getHeight());
	ofPopMatrix();
	ofSetColor(ofColor::white);
}
// Fonction permettant d'ajuster la teinte des pixels de l'image
void Image::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
// On parcours tous les pixels de l'image
	for (int i = 0; i < image->getWidth(); i++)
	{
		for (int j = 0; j < image->getHeight(); j++)
		{
			// On récupère la couleur du pixel
			ofColor finalColor = image->getColor(i, j);
			// On ajuste la teinte de chaque couleur
			finalColor.r = (originalColor[i][j].r + color.r) / 2;
			finalColor.g = (originalColor[i][j].g + color.g) / 2;
			finalColor.b = (originalColor[i][j].b + color.b) / 2;
			finalColor.a = color.a;
			// On modifie le pixel
			image->setColor(i, j, finalColor);
		}
	}
}
// Fonction permettant d'ajuster la composante de transparence de l'image
void Image::SetAlpha(int a)
{
	// On parcours chaque pixel de l'image
	for (int i = 0; i < image->getWidth(); i++)
	{
		for (int j = 0; j < image->getHeight(); j++)
		{
			// On récupère la couleur du pixel
			ofColor color = image->getColor(i, j);
			// On ajuste sa composante de transparence
			color.a = a;
			// On modifie le pixel
			image->setColor(i, j, color);
		}
	}
}
// Détermination de la collision entre le clic de la souris et l'image 
bool Image::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return mouse.x >= objScreenPos.x && mouse.y >= objScreenPos.y - (image->getHeight() * 0.5f) && 
		   mouse.x <= objScreenPos.x + (image->getWidth() * 0.5f) && mouse.y <= objScreenPos.y;
}

