#ifndef GUI_H
#define GUI_H

#include "ofxGui.h"

#include "ofMain.h"

class Gui
{
public:
	Gui();
	~Gui();

	void Setup();
	void Update();
	void Draw();

	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofxButton& GetCreateBoxButton() { return createCubeButton; }
	ofxButton& GetCreateSphereButton() { return createSphereButton; }
	ofxButton& GetCreateImageButton() { return createImageButton; }
	ofxButton& GetCreateLemniscateButton() { return createLemniscateButton; }

private:
	ofxButton createCubeButton;
	ofxButton createSphereButton;
	ofxButton createImageButton;
	ofxButton createLemniscateButton;

	ofxPanel gui;
};

#endif //GUI_H
