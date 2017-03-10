#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H

#include "base3DObject.h"

class ModeObj : public Base3DObject
{
public:
	ModeObj();
	ModeObj(int x, int y, int z, float radius);
	~ModeObj();

private:
	void Load();
};

#endif // MODEL_OBJ_H