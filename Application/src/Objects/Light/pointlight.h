#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light.h"

class PointLight : public Light
{
public:
	PointLight();
	PointLight(float x, float y, float z);
	~PointLight();
	
	void Load();

protected:

private:
};

#endif // POINT_LIGHT_H