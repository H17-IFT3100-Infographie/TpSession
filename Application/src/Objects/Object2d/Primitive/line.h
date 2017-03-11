#ifndef LINE_H
#define LINE_H

#include "primitive.h"

class Line : public Primitive
{
public:
	Line(ofPoint p1, ofPoint p2, float stroke, ofColor color = ofColor::black);
	~Line();
	
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetAlpha(int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:
	Line();

	ofPoint endPoint;
};

#endif // LINE_H