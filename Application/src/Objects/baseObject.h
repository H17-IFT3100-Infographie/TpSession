#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include <of3dPrimitives.h>

class BaseObject : public of3dPrimitive
{
public:
	BaseObject();
	BaseObject(float x, float y, float z);
	~BaseObject();

	virtual void Draw();

	inline void SetPosition(float x, float y, float z);
	inline void Translate(const ofVec3f& translateBy);

	virtual bool IsHovered(float x, float y);

protected:
	of3dPrimitive* m_3dPrimitive;
	ofVec3f position;
private:
	
};

void BaseObject::SetPosition(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void BaseObject::Translate(const ofVec3f& translateBy)
{
	position += translateBy;
}


#endif // BASE_OBJECT_H