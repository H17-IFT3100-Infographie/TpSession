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
	virtual void Setup();

	virtual void Update();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
};

#endif // AMBIANT_LIGHT_H