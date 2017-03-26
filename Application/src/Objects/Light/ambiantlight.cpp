#include "ambiantlight.h"

// Constructeur de la classe DirectionalLight
AmbiantLight::AmbiantLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::AMBIANT, "lights/ambiantlight.png")
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
AmbiantLight::AmbiantLight(float x, float y, float z)
	: Light(x, y, z, ELightType::AMBIANT, "lights/ambiantlight.png")
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
	light.setAreaLight(0.0f, 0.0f);

	// Initialisation de la lumiere
	Setup();
}
