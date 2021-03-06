#ifndef LIGHT_H
#define LIGHT_H

#include "baseObject.h"
#include "../Object2d/image.h"

#include <ofLight.h>

/**
If an ofLight is drawn within the context of a camera such as ofEasyCam,
its position and orientation will be controlled by the camera and it will
be oriented relative to the scene focus of the camera.
**/

class Light : public BaseObject
{
public:

	enum ELightType
	{
		DIRECTIONAL,
		POINT,
		AMBIANT,
		SPOT
	};

	Light(const ELightType lightType, const std::string& guiFilepath);
	Light(float x, float y, float z, const ELightType lightType, const std::string& guiFilepath);
	~Light();

	void Load();
	virtual void Setup();
	virtual void Draw();
	virtual void Update();
	void Enable();
	void Disable();
	virtual void DrawBoundingBox();

	virtual void SetColor(int r, int g, int b, int a);

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:

	ofLight light;
	ELightType type;

	Image* gui;
	std::string guiFilepath;

private:

};

#endif // LIGHT_H