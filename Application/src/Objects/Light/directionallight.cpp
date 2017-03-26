#include "directionallight.h"

// Constructeur de la classe DirectionalLight
DirectionalLight::DirectionalLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::DIRECTIONAL, "lights/directionallight.png")
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
DirectionalLight::DirectionalLight(float x, float y, float z)
	: Light(x, y, z, ELightType::DIRECTIONAL, "lights/directionallight.png")
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

	light.setDirectional();
	light.setOrientation(ofVec3f(0, 90, 0));

	// Initialisation de la lumiere
	Setup();
}
