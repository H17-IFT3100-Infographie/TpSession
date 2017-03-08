#ifndef CUBE_H
#define CUBE_H

#include "baseObject.h"

class Box : public BaseObject
{
public:
	Box(int x, int y, int z, int width, int height, int depth);
	~Box();

	void Setup(int posX, int posY, int posZ, int width, int height, int depth);

private:
	Box();
};

#endif // CUBE_H