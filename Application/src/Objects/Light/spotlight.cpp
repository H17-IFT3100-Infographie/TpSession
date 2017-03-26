#include "spotlight.h"

// Constructeur de la classe DirectionalLight
SpotLight::SpotLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::SPOT)
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
SpotLight::SpotLight(float x, float y, float z)
	: Light(x, y, z, ELightType::SPOT)
{
	Load();
}

// Destructeur de la classe DirectionalLight
SpotLight::~SpotLight()
{

}

// Fonction permettant de charger une image
void SpotLight::Load()
{
	Light::Load();

	light->setDiffuseColor(ofColor(255.0f, 0.0f, 0.0));
	light->setSpecularColor(ofColor(255.0f, 255.0f, 255.0f));
	light->setSpotlight();

	// size of the cone of emitted light, angle between light axis and side of cone //
	// angle range between 0 - 90 in degrees //
	light->setSpotlightCutOff(50);

	// rate of falloff, illumitation decreases as the angle from the cone axis increases //
	// range 0 - 128, zero is even illumination, 128 is max falloff //
	light->setSpotConcentration(45);


	// Initialisation de la lumiere
	Setup();
}
// Fonction permettant l'initialisation de paramètres
void SpotLight::Setup()
{
}

// Fonction permettant la mise à jour des paramètres de l'image
void SpotLight::Update()
{
}

// Fonction permettant de déterminer les frontières d'une image
void SpotLight::DrawBoundingBox()
{

}

// Fonction permettant d'ajuster la teinte des pixels de l'image
void SpotLight::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);

}

// Détermination de la collision entre le clic de la souris et l'image 
bool SpotLight::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) 
{ 
	return false;
}

