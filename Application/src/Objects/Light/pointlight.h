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
	virtual void Setup();

	virtual void Update();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
};

#endif // POINT_LIGHT_H