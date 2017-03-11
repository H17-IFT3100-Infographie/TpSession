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

	virtual bool IsHovered(float x, float y);
protected:
	of3dPrimitive* m_3dPrimitive;
private:
	
};

#endif // BASE_3D_OBJECT_H