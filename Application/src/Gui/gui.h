#ifndef GUI_H
#define GUI_H

#include "baseGui.h"
#include "ofxGuiAddons/ofxInputField.h"

class Gui : public BaseGui
{
public:
	Gui();
	~Gui();

	virtual void Setup();

	ofxButton& GetCreateBoxButton() { return createCubeButton; }
	ofxButton& GetCreateSphereButton() { return createSphereButton; }
	ofxButton& GetCreateModelButton() { return createModelButton; }
	ofxButton& GetCreateImageButton() { return createImageButton; }
	ofxButton& GetCreateLemniscateButton() { return createLemniscateButton; }

	ofxTextField& GetImageInputField() { return imageInputField; }

	virtual bool IsAnyGuiFocused();

private:
	ofxButton createCubeButton;
	ofxButton createSphereButton;
	ofxButton createModelButton;
	ofxButton createImageButton;
	ofxButton createLemniscateButton;
	ofxTextField imageInputField;
};

#endif //GUI_H
