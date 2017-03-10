#ifndef TRANSFORM_GUI_H
#define TRANSFORM_GUI_H

#include "ofxGui.h"

#include "ofMain.h"
#include "ofxGuiAddons/ofxInputField.h"
#include "Objects\baseObject.h"

class TransformGui
{
public:
	TransformGui();
	~TransformGui();

	void Setup();
	void Update(BaseObject* currentObjectSelected);
	void Draw();

	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void SetPosXValue(int value) { posXField.SetValue(value); }
	void SetPosYValue(int value) { posYField.SetValue(value); }
	void SetPosZValue(int value) { posZField.SetValue(value); }

	void PosEntered();

private:
	ofxPanel gui;

	ofxIntField posXField;
	ofxIntField posYField;
	ofxIntField posZField;

	bool posIsDirty;
};

#endif //TRANSFORM_GUI_H
