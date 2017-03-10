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
	ofxButton& GetCreateImageButton() { return createImageButton; }
	ofxButton& GetCreateLemniscateButton() { return createLemniscateButton; }
	ofxButton& GetCreateModelButton() { return createModelButton; }
	ofxTextField& GetImageInputField() { return imageInputField; }

	virtual bool IsAnyGuiFocused();

private:
	ofxButton createCubeButton;
	ofxButton createSphereButton;
	ofxButton createImageButton;
	ofxButton createLemniscateButton;
	ofxButton createModelButton;
	ofxTextField imageInputField;
};

#endif //GUI_H
