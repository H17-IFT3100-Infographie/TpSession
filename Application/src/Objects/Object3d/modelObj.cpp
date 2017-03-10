#include "modelObj.h"

ModeObj::ModeObj()
	: Base3DObject(0.0f, 0.0f, 0.0f)
{
	Load();
}

ModeObj::ModeObj(int x, int y, int z, float radius)
	: Base3DObject(x, y, z)
{
	Load();
}

ModeObj::~ModeObj()
{
}

void ModeObj::Load()
{

}