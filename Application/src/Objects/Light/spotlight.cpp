#include "spotlight.h"

// Constructeur de la classe DirectionalLight
SpotLight::SpotLight()
	: Light(0.0f, 0.0f, 0.0f, ELightType::SPOT, "lights/spotlight.png")
{
	Load();
	
}

// Constructeur de la classe Image avec 3 positions
SpotLight::SpotLight(float x, float y, float z)
	: Light(x, y, z, ELightType::SPOT, "lights/spotlight.png")
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

	light.setDiffuseColor(ofColor(255.0f, 0.0f, 0.0));
	light.setSpecularColor(ofColor(255.0f, 255.0f, 255.0f));
	light.setSpotlight();

	// size of the cone of emitted light, angle between light axis and side of cone //
	// angle range between 0 - 90 in degrees //
	light.setSpotlightCutOff(50);

	// rate of falloff, illumitation decreases as the angle from the cone axis increases //
	// range 0 - 128, zero is even illumination, 128 is max falloff //
	light.setSpotConcentration(45);


	// Initialisation de la lumiere
	Setup();
}
