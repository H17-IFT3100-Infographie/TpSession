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

	ofxButton& GetCreateQuadratic() { return createQuadratic; }
	ofxButton& GetCreateCubic() { return createCubic; }
	ofxButton& GetCreateHermite() { return createHermite; }

	ofxButton& GetCreateDirectionalLight() { return createDirectionalLight; }
	ofxButton& GetCreatePointLight() { return createPointLight; }
	ofxButton& GetCreateAmbiantLight() { return createAmbiantLight; }
	ofxButton& GetCreateSpotLight() { return createSpotLight; }

	ofxToggle& GetMaterial1Toggle() { return material1Toggle; }
	ofxToggle& GetMaterial2Toggle() { return material2Toggle; }
	ofxToggle& GetMaterial3Toggle() { return material3Toggle; }

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
	
	ofxButton createQuadratic;
	ofxButton createCubic;
	ofxButton createHermite;

	ofxToggle material1Toggle;
	ofxToggle material2Toggle;
	ofxToggle material3Toggle;
};

#endif //GUI_H
