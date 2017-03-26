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
	virtual void Setup();

	virtual void Update();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
};

#endif // SPOT_LIGHT_H