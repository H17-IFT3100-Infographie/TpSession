#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include <of3dPrimitives.h>
#include <ofEasyCam.h>

class BaseObject : public of3dPrimitive
{
public:
	BaseObject(float x, float y, float z);
	BaseObject(const ofVec3f& pos);
	~BaseObject();

	virtual void Setup();

	virtual void Update();
	virtual void Draw();

	inline void SetPosition(float x, float y, float z);
	inline void Translate(const ofVec3f& translateBy);

	virtual void SetColor(int r, int g, int b) { }
	void SetColor(const ofColor& color) { SetColor(color.r, color.g, color.b); }
	virtual void SetAlpha(int a) { }

	virtual bool Inside(int x, int y, int z, const ofEasyCam& cam) { return false; }

	ofVec3f pos;
	ofVec3f rot;
	ofVec3f scale;
protected:

private:
	
};

void BaseObject::SetPosition(float x, float y, float z)
{
	pos = ofVec3f(x, y, z);
}

void BaseObject::Translate(const ofVec3f& translateBy)
{
	//m_3dPrimitive->setPosition(m_3dPrimitive->getPosition() + translateBy);
}


#endif // BASE_OBJECT_H