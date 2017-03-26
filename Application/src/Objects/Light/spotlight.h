#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "light.h"

class SpotLight : public Light
{
public:
	SpotLight();
	SpotLight(float x, float y, float z);
	~SpotLight();
	
	void Load();

protected:

private:
};

#endif // SPOT_LIGHT_H