#ifndef CUBIC_H
#define CUBIC_H

#include "baseObject.h"
#include "../sphere.h"

#include <ofPolyline.h>

class Cubic : public BaseObject
{
public:

	inline void bezierCubic(
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

		x = uuu * p1x + 3 * uu * t * p2x + 3 * u * tt * p3x + ttt * p4x;
		y = uuu * p1y + 3 * uu * t * p2y + 3 * u * tt * p3y + ttt * p4y;
		z = uuu * p1z + 3 * uu * t * p2z + 3 * u * tt * p3z + ttt * p4z;
	}

	Cubic(bool drawSurface = false);
	Cubic(float x, float y, float z, bool drawSurface = false);
	~Cubic();
	
	void Load();
	virtual void Setup();

	virtual void Update();
	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);
	virtual void SetAlpha(int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

	Sphere* GetFirstNode() { return listCrtlPoints[0]; }
	void ReplaceLastNodeBy(Sphere* byNode);

	void CreateSurfaces();

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
	ofMesh triangle1;
	ofMesh triangle2;

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

	bool drawSurface;
};

#endif // IMAGE_H