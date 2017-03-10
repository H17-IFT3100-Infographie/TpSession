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

private:
	ofxButton createCubeButton;
	ofxButton createSphereButton;
	ofxPanel gui;
};

#endif //GUI_H
