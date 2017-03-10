#ifndef MULTI_TRANSFORM_GUI_H
#define MULTI_TRANSFORM_GUI_H

#include "baseGui.h"
#include "ofxGuiAddons/ofxInputField.h"


class MultiTransformGui : public BaseGui
{
public:
	MultiTransformGui();
	~MultiTransformGui();

	void Setup();
	void Update(std::vector<BaseObject*>& currentObjectSelected);

	virtual bool IsAnyGuiFocused();

private:
	void UpdatePosition(std::vector<BaseObject*>& currentObjectSelected);
	void UpdateRotation(std::vector<BaseObject*>& currentObjectSelected);
	void UpdateScale(std::vector<BaseObject*>& currentObjectSelected);

	ofVec3f pos;
	ofxIntField posXField;
	ofxIntField posYField;
	ofxIntField posZField;

	ofVec3f rot;
	ofxIntField rotXField;
	ofxIntField rotYField;
	ofxIntField rotZField;

	ofVec3f scale;
	ofxFloatField scaleXField;
	ofxFloatField scaleYField;
	ofxFloatField scaleZField;
};

#endif //MULTI_TRANSFORM_GUI_H
