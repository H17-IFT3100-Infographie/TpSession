#ifndef QUADRATIC_H
#define QUADRATIC_H

#include "baseObject.h"
#include "../sphere.h"

#include <ofPolyline.h>

class Quadratic : public BaseObject
{
public:

	// fonction d'évaluation d'une courbe de Bézier quadratique (3 points de contrôle)
	inline void bezierQuadratic(
		float t,
		float p1x, float p1y, float p1z,
		float p2x, float p2y, float p2z,
		float p3x, float p3y, float p3z,
		float&  x, float& y, float&  z)
	{
		float u = 1 - t;

		x = u * (u * p1x + t * p2x) + t * (u * p2x + t * p3x);
		y = u * (u * p1y + t * p2y) + t * (u * p2y + t * p3y);
		z = u * (u * p1z + t * p2z) + t * (u * p2z + t * p3z);
	}

	Quadratic();
	Quadratic(float x, float y, float z);
	~Quadratic();
	
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