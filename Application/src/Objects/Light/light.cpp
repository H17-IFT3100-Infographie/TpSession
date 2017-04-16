#include "directionallight.h"

// Constructeur de la classe
Light::Light(const ELightType lightType, const std::string& guiFilepath)
	: BaseObject(0.0f, 0.0f, 0.0f)
	, type(lightType)
	, guiFilepath(guiFilepath)
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
Light::Light(float x, float y, float z, const ELightType lightType, const std::string& guiFilepath)
	: BaseObject(x, y, z)
	, type(lightType)
	, guiFilepath(guiFilepath)
{
	Load();
}
// Destructeur de la classe
Light::~Light()
{
	if (nullptr != gui)
	{
		delete gui;
		gui = nullptr;
	}
}

// Fonction permettant de charger une lumiere
void Light::Load()
{
	gui = new Image(guiFilepath);

	// Initialisation de la lumiere
	Setup();
}

// Fonction permettant l'initialisation de param�tres
void Light::Setup()
{
}
// Fonction permettant la mise � jour des param�tres
void Light::Update()
{
	gui->pos = pos;
	gui->Update();
}

void Light::Draw()
{
	gui->Draw();
}

// Fonction permettant le rendu graphique
void Light::Enable()
{
	//light.setAmbientColor(color);
	//light.setDiffuseColor(color);
	
	light.setPosition(pos);
	light.setOrientation(rot);
	light.enable();
}

void Light::Disable()
{
	light.disable();
}

// Fonction permettant de d�terminer les fronti�res
void Light::DrawBoundingBox()
{
	gui->DrawBoundingBox();
}

// Fonction permettant d'ajuster la couleur
void Light::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
}

// D�termination de la collision entre le clic de la souris et l'image 
bool Light::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return gui->CheckPointCollision(mouse, objScreenPos);
}

