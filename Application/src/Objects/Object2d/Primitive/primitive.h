#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include "baseObject.h"
#include "ofMain.h"

class Primitive : public BaseObject
{
public:
	Primitive(ofPoint pos, float stroke, ofColor color = ofColor::black);
	Primitive(ofPoint pos, float stroke, bool fill, ofColor color = ofColor::black);
	~Primitive();
	
	virtual void Setup();

	virtual void Update();

	virtual void PreDraw();
	virtual void Draw();
	virtual void PostDraw();

	virtual void DrawBoundingBox() {}

	virtual void SetAlpha(int a);

	bool IsHovered(float x, float y);

protected:
	float stroke;
	bool fill;
private:
	Primitive();
};

#endif // PRIMITIVE_H