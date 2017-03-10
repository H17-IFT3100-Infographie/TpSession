#ifndef TRANSFORM_GUI_H
#define TRANSFORM_GUI_H

#include "baseGui.h"
#include "ofxGuiAddons/ofxInputField.h"


class TransformGui : public BaseGui
{
public:
	TransformGui();
	~TransformGui();

	void Setup();
	void Update(BaseObject* currentObjectSelected = nullptr);

	void SetPosXValue(int value) { posXField.SetValue(value); }
	void SetPosYValue(int value) { posYField.SetValue(value); }
	void SetPosZValue(int value) { posZField.SetValue(value); }

	virtual bool IsAnyGuiFocused();

private:
	ofxIntField posXField;
	ofxIntField posYField;
	ofxIntField posZField;
};

#endif //TRANSFORM_GUI_H
