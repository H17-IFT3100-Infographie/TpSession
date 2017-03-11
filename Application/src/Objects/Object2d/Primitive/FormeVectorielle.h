#pragma once
#include "primitive.h"
#include "circle.h"
#include "rect.h"
class FormeVectorielle : public Primitive
{
public:
	FormeVectorielle(ofPoint center, float radius, float stroke, bool fill, ofColor color);
	~FormeVectorielle();
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetAlpha(int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:


	float radius;
};
