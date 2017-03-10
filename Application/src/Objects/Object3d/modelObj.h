#ifndef MODEL_OBJ_H
#define MODEL_OBJ_H

#include "base3DObject.h"
#include "ofxAssimpModelLoader.h"

class ModelObj : public Base3DObject
{
public:
	ModelObj();
	ModelObj(const std::string filepath);
	ModelObj(int x, int y, int z, float radius);
	~ModelObj();	
protected:
	ofxAssimpModelLoader* modele;


private:	
	std::string filepath;
	void Load();
	void Setup();	 
	void Update();
	void Draw();
};

#endif // MODEL_OBJ_H