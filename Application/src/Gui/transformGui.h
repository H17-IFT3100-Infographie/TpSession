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

	void SetRotXValue(int value) { rotXField.SetValue(value); }
	void SetRotYValue(int value) { rotYField.SetValue(value); }
	void SetRotZValue(int value) { rotZField.SetValue(value); }

	void SetScaleXValue(int value) { scaleXField.SetValue(value); }
	void SetScaleYValue(int value) { scaleYField.SetValue(value); }
	void SetScaleZValue(int value) { scaleZField.SetValue(value); }

	void OnSelected(BaseObject* currentObjectSelected);
	virtual bool IsAnyGuiFocused();

private:
	void UpdatePosition(BaseObject* currentObjectSelected);
	void UpdateRotation(BaseObject* currentObjectSelected);
	void UpdateScale(BaseObject* currentObjectSelected);
	void UpdateColor(BaseObject* currentObjectSelected);
	void UpdateAlpha(BaseObject* currentObjectSelected);


	ofxIntField posXField;
	ofxIntField posYField;
	ofxIntField posZField;

	ofxIntField rotXField;
	ofxIntField rotYField;
	ofxIntField rotZField;

	ofxFloatField scaleXField;
	ofxFloatField scaleYField;
	ofxFloatField scaleZField;

	ofxColorSlider colorSlider;
};

#endif //TRANSFORM_GUI_H
