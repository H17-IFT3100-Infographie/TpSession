#include "pointlight.h"

// Constructeur de la classe DirectionalLight
PointLight::PointLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::POINT, "lights/pointlight.png")
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
PointLight::PointLight(float x, float y, float z)
	: Light(x, y, z, ELightType::POINT, "lights/pointlight.png")
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

	light.setPointLight();

	// Initialisation de la lumiere
	Setup();
}