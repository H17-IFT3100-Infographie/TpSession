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

	bool IsHovered(float x, float y);

protected:

private:
	Line();

	ofPoint endPoint;
};

#endif // LINE_H