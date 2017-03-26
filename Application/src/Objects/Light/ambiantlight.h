#ifndef AMBIANT_LIGHT_H
#define AMBIANT_LIGHT_H

#include "light.h"

class AmbiantLight : public Light
{
public:
	AmbiantLight();
	AmbiantLight(float x, float y, float z);
	~AmbiantLight();
	
	void Load();

protected:

private:
};

#endif // AMBIANT_LIGHT_H