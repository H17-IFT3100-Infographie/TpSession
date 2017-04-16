#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H

#include "base3DObject.h"
#include "ofxAssimpModelLoader.h"
#include "box.h"

class ModelObj : public Base3DObject
{
public:
	ModelObj();
	ModelObj(const std::string filepath);
	ModelObj(int x, int y, int z, float radius);
	~ModelObj();	

	virtual void DrawBoundingBox();

	virtual bool CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos);

protected:
	ofxAssimpModelLoader* modele;
private:	
	std::string filepath;
	void Load();
	void Setup();	 
	void Update();
	void Draw();
	ofMaterial material;
	ofVec3f currentRotation;
	ofVec3f nextRotation;

	ofVec3f dimension;
	Box* boundingBox;
};

#endif // MODEL_OBJ_H