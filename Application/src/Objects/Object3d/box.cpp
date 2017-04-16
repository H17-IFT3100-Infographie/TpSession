#include "box.h"
// Constructeur de la classe box sans param�tres et avec initialisation
Box::Box()
	: Base3DObject(0.0f, 0.0f, 0.0f)
	, dimensions(100, 100, 100)
{
	Load();
}
// Constructeur de la classe box avec 6 param�tres, x,y,z, longueur, largeur, profondeur
Box::Box(float x, float y, float z, int width, int height, int depth)
	: Base3DObject(x, y, z)
	, dimensions(width, height, depth)
{
	Load();
}
// Constructeur de la classe bo�te avec 4 param�tres, une position, longueur, largeur, profondeur
Box::Box(const ofVec3f& position, int width, int height, int depth)
	: Base3DObject(position)
	, dimensions(width, height, depth)
{
	Load();
}
// Fonction permettant l'instanciation et le chargement de param�tres de la bo�te
void Box::Load()
{
	primitive = new ofBoxPrimitive(dimensions.x, dimensions.y, dimensions.z);

}
// Destructeur de la classe bo�te
Box::~Box()
{
}
// D�termination de la collision entre le clic de la souris et la bo�te
bool Box::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return mouse.x >= objScreenPos.x - (dimensions.x * 0.25f) * scale.x && mouse.y >= objScreenPos.y - (dimensions.y * 0.25f) * scale.y &&
		   mouse.x <= objScreenPos.x + (dimensions.x * 0.25f) * scale.x && mouse.y <= objScreenPos.y + (dimensions.y * 0.25f) * scale.y;
}