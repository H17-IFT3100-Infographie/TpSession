#include "ambiantlight.h"

// Constructeur de la classe DirectionalLight
AmbiantLight::AmbiantLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::AMBIANT)
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
AmbiantLight::AmbiantLight(float x, float y, float z)
	: Light(x, y, z, ELightType::AMBIANT)
{
	Load();
}

// Destructeur de la classe DirectionalLight
AmbiantLight::~AmbiantLight()
{

}

// Fonction permettant de charger une image
void AmbiantLight::Load()
{
	Light::Load();

	// TODO: Plug width and height
	light->setAreaLight(0.0f, 0.0f);

	// Initialisation de la lumiere
	Setup();
}
// Fonction permettant l'initialisation de paramètres
void AmbiantLight::Setup()
{
}

// Fonction permettant la mise à jour des paramètres de l'image
void AmbiantLight::Update()
{
}

// Fonction permettant de déterminer les frontières d'une image
void AmbiantLight::DrawBoundingBox()
{

}

// Fonction permettant d'ajuster la teinte des pixels de l'image
void AmbiantLight::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

}

// Détermination de la collision entre le clic de la souris et l'image 
bool AmbiantLight::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

