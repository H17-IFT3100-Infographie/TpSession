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
	ofxButton& GetCreateRectangleButton() { return createRectButton; }
	ofxButton& GetCreateLineButton() { return createLineButton; }
	ofxButton& GetCreateCercleButton() { return createCercleButton; }
	ofxButton& GetCreateFVButton() { return createFVButton; }

	ofxButton& GetCreateBoxButton() { return createCubeButton; }
	ofxButton& GetCreateSphereButton() { return createSphereButton; }
	ofxButton& GetCreateOctahedreButton() { return createOctahedreButton; }
	ofxButton& GetCreateModelButton() { return createModelButton; }
	
	ofxButton& GetCreateImageButton() { return createImageButton; }
	ofxButton& GetCreateLemniscateButton() { return createLemniscateButton; }
	ofxButton& GetHSBButton() { return modeHSBButton; }

	ofxButton& GetCreateDirectionalLight() { return createDirectionalLight; }
	ofxButton& GetCreatePointLight() { return createPointLight; }
	ofxButton& GetCreateAmbiantLight() { return createAmbiantLight; }
	ofxButton& GetCreateSpotLight() { return createSpotLight; }

	ofxButton& GetShowCamOption() { return gotoCamOptions; }

	ofxTextField& GetImageInputField() { return imageInputField; }

	virtual bool IsAnyGuiFocused();

private:
	ofxButton modeHSBButton;
	ofxButton createRectButton;
	ofxButton createLineButton;
	ofxButton createCercleButton;
	ofxButton createFVButton;
	ofxButton createCubeButton;
	ofxButton createSphereButton;
	ofxButton createModelButton;
	ofxButton createImageButton;
	ofxButton createLemniscateButton;
	ofxTextField imageInputField;
	ofxButton createOctahedreButton;
	ofxButton gotoCamOptions;

	ofxButton createDirectionalLight;
	ofxButton createPointLight;
	ofxButton createAmbiantLight;
	ofxButton createSpotLight;
};

#endif //GUI_H
