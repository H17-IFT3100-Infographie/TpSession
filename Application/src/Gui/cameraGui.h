#ifndef CAMERA_GUI_H
#define CAMERA_GUI_H

#include "baseGui.h"
#include "ofxInputField.h"

class CameraGui : public BaseGui
{
public:
	CameraGui();
	~CameraGui();

	virtual void Setup();

	ofxToggle& GetPerspToggle() { return perspToggle; }
	ofxToggle& GetOrhtoToggle() { return orthoToggle; }
	ofxButton& GetObjectCreatorButton() { return showObjectsCreator; }
	ofxToggle& GetGridActivatorToggle() { return gridActivatorToggle; }

	ofxFloatField& GetFovField() { return fovField; }
	ofxFloatField& GetAspectRatio() { return aspectRatio; }
	ofxFloatField& GetFarClipping() { return farClipping; }
	ofxFloatField& GetNearClipping() { return nearClipping; }

private:

	ofxToggle perspToggle;
	ofxToggle orthoToggle;
	ofxToggle gridActivatorToggle;

	ofxFloatField fovField;
	ofxFloatField aspectRatio;
	ofxFloatField farClipping;
	ofxFloatField nearClipping;

	ofxButton showObjectsCreator;
};

#endif //CAMERA_GUI_H
