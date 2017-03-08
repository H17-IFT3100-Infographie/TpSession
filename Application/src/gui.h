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

private:
	ofxFloatSlider radius;
	ofxColorSlider color;
	ofxVec2Slider center;
	ofxIntSlider circleResolution;
	ofxToggle filled;
	ofxButton twoCircles;
	ofxButton ringButton;
	ofxLabel screenSize;

	ofxPanel gui;
};

#endif //GUI_H
