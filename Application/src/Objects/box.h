#ifndef CUBE_H
#define CUBE_H

#include "base3DObject.h"

class Box : public Base3DObject
{
public:
	Box();
	Box(float x, float y, float z, int width, int height, int depth);
	Box(const ofVec3f& position, int width, int height, int depth);
	~Box();
	
	bool IsHovered(float x, float y);

private:
	

	ofVec3f dimensions;
};

#endif // CUBE_H