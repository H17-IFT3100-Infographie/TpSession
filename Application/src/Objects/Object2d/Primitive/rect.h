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
	virtual void DrawBoundingBox();
	
	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

	void SetDimension(float w, float h) { SetWidth(w); SetHeight(h); }
	void SetWidth(float w) { width = w; }
	void SetHeight(float h) { height = h; }

protected:

private:
	Rect();

	float width;
	float height;
};

#endif // RECTANGLE_H