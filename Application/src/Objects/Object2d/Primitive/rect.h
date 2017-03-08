#ifndef RECT_H
#define RECT_H

#include "primitive.h"

class Rect : public Primitive
{
public:
	Rect(ofPoint tl, ofPoint br, float stroke, bool fill = true, ofColor color = ofColor::black);
	~Rect();
	
	virtual void Setup();

	virtual void Update();
	virtual void Draw();

	bool IsHovered(float x, float y);

protected:

private:
	Rect();

	ofPoint bottomRight;
};

#endif // RECTANGLE_H