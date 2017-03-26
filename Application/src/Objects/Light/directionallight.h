#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "light.h"

class DirectionalLight : public Light
{
public:
	DirectionalLight();
	DirectionalLight(float x, float y, float z);
	~DirectionalLight();
	
	void Load();

protected:

private:
};

#endif // DIRECTIONAL_LIGHT_H