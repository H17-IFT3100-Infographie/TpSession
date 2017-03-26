#include "pointlight.h"

// Constructeur de la classe DirectionalLight
PointLight::PointLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::POINT)
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
PointLight::PointLight(float x, float y, float z)
	: Light(x, y, z, ELightType::POINT)
{
	Load();
}

// Destructeur de la classe DirectionalLight
PointLight::~PointLight()
{

}

// Fonction permettant de charger une image
void PointLight::Load()
{
	Light::Load();

	light->setPointLight();

	// Initialisation de la lumiere
	Setup();
}
// Fonction permettant l'initialisation de paramètres
void PointLight::Setup()
{
}

// Fonction permettant la mise à jour des paramètres de l'image
void PointLight::Update()
{
}

// Fonction permettant de déterminer les frontières d'une image
void PointLight::DrawBoundingBox()
{

}

// Fonction permettant d'ajuster la teinte des pixels de l'image
void PointLight::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

}

// Détermination de la collision entre le clic de la souris et l'image 
bool PointLight::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{
	return false;
}

