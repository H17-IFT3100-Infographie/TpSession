#include "directionallight.h"

// Constructeur de la classe DirectionalLight
DirectionalLight::DirectionalLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::DIRECTIONAL)
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
DirectionalLight::DirectionalLight(float x, float y, float z)
	: Light(x, y, z, ELightType::DIRECTIONAL)
{
	Load();
}

// Destructeur de la classe DirectionalLight
DirectionalLight::~DirectionalLight()
{

}

// Fonction permettant de charger une image
void DirectionalLight::Load()
{
	Light::Load();

	light->setDirectional();
	light->setOrientation(ofVec3f(0, 90, 0));

	// Initialisation de la lumiere
	Setup();
}
// Fonction permettant l'initialisation de param�tres
void DirectionalLight::Setup()
{
}

// Fonction permettant la mise � jour des param�tres de l'image
void DirectionalLight::Update()
{
}

// Fonction permettant de d�terminer les fronti�res d'une image
void DirectionalLight::DrawBoundingBox()
{

}

// Fonction permettant d'ajuster la teinte des pixels de l'image
void DirectionalLight::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

}

// D�termination de la collision entre le clic de la souris et l'image 
bool DirectionalLight::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

