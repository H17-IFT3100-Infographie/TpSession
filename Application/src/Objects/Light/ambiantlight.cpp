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
// Fonction permettant l'initialisation de param�tres
void AmbiantLight::Setup()
{
}

// Fonction permettant la mise � jour des param�tres de l'image
void AmbiantLight::Update()
{
}

// Fonction permettant de d�terminer les fronti�res d'une image
void AmbiantLight::DrawBoundingBox()
{

}

// Fonction permettant d'ajuster la teinte des pixels de l'image
void AmbiantLight::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

}

// D�termination de la collision entre le clic de la souris et l'image 
bool AmbiantLight::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

