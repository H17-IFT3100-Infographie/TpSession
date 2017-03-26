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
	virtual void Setup();

	virtual void Update();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
};

#endif // DIRECTIONAL_LIGHT_H