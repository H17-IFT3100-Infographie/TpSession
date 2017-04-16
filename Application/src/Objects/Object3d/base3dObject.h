#ifndef BASE_3D_OBJECT_H
#define BASE_3D_OBJECT_H

#include "baseObject.h"

class Base3DObject : public BaseObject
{
public:
	Base3DObject(float x, float y, float z);
	Base3DObject(const ofVec3f& pos);
	~Base3DObject();

	virtual void Draw();
	virtual void DrawBoundingBox();

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos) { return false; }
protected:
	of3dPrimitive* primitive;
private:
};

#endif // BASE_3D_OBJECT_H