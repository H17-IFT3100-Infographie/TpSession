#ifndef BSPLINE_H
#define BSPLINE_H

#include "baseObject.h"

#include "../Beziers/cubic.h"

class BSpline : public BaseObject
{
public:

	BSpline();
	BSpline(float x, float y, float z);
	~BSpline();

	void Load();
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);
	virtual void SetAlpha(int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

private:

	void reset();

	Cubic* firstCubic;
	Cubic* secondCubic;
};

#endif // IMAGE_H