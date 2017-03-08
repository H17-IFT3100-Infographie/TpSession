#ifndef CUBE_H
#define CUBE_H

#include "baseObject.h"

class Box : public BaseObject
{
public:
	Box(int x, int y, int z, int width, int height, int depth);
	~Box();
	
	bool IsHovered(float x, float y);

private:
	Box();

	ofVec3f dimensions;
};

#endif // CUBE_H