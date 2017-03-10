#ifndef CAMERA_GUI_H
#define CAMERA_GUI_H

#include "baseGui.h"

class CameraGui : public BaseGui
{
public:
	CameraGui();
	~CameraGui();

	virtual void Setup();

	ofxToggle& GetPerspToggle() { return perspToggle; }
	ofxToggle& GetOrhtoToggle() { return orthoToggle; }
	ofxButton& GetObjectCreatorButton() { return showObjectsCreator; }

private:

	ofxToggle perspToggle;
	ofxToggle orthoToggle;

	ofxButton showObjectsCreator;
};

#endif //CAMERA_GUI_H
