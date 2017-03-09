#ifndef RECT_H
#define RECT_H

#include "primitive.h"

class Rect : public Primitive
{
public:
	Rect(ofPoint tl, float width, float height, float stroke, bool fill = true, ofColor color = ofColor::black);
	~Rect();
	
	virtual void Setup();

	virtual void Update();
	virtual void Draw();

	bool IsHovered(float x, float y);

protected:

private:
	Rect();

	float width;
	float height;
};

#endif // RECTANGLE_H