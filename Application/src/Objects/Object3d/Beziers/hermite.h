#ifndef HERMITE_H
#define HERMITE_H

#include "baseObject.h"
#include "../sphere.h"

#include <ofPolyline.h>

class Hermite : public BaseObject
{
public:

	inline void hermite(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float p4x, float p4y, float p4z,
		float&  x, float& y, float&  z)
	{
		float u = 1 - t;
		float uu = u * u;
		float uuu = uu * u;
		float tt = t * t;
		float ttt = tt * t;

		x = (2 * ttt - 3 * tt + 1) * p1x + (ttt - 2 * tt + t) * p2x + (ttt - tt) * p3x + (-2 * ttt + 3 * tt) * p4x;
		y = (2 * ttt - 3 * tt + 1) * p1y + (ttt - 2 * tt + t) * p2y + (ttt - tt) * p3y + (-2 * ttt + 3 * tt) * p4y;
		z = (2 * ttt - 3 * tt + 1) * p1z + (ttt - 2 * tt + t) * p2z + (ttt - tt) * p3z + (-2 * ttt + 3 * tt) * p4z;
	}

	Hermite();
	Hermite(float x, float y, float z);
	~Hermite();
	
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

	ofPolyline lineRenderer;

	ofVec3f initialPosition1;
	ofVec3f initialPosition2;
	ofVec3f initialPosition3;
	ofVec3f initialPosition4;
	ofVec3f initialPosition5;

	ofVec3f position;

	std::vector<Sphere*> listCrtlPoints;

	float lineWidthOutline;
	float lineWidthCurve;

	float radius;
	float scale;
	float smooth;
	float offset;

	float xDelta;
	float yDelta;

	float motionSpeed;

	int framebufferWidth;
	int framebufferHeight;

	int lineResolution;

	int index;
};

#endif // IMAGE_H