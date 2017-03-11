#ifndef CIRCLE_H
#define CIRCLE_H

#include "primitive.h"

class Circle : public Primitive
{
public:
	Circle(ofPoint center, float radius, float stroke, bool fill = true, ofColor color = ofColor::black);
	~Circle();
	
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetAlpha(int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
	Circle();

	float radius;
};

#endif // CIRCLE_H