#ifndef TRANSFORM_GUI_H
#define TRANSFORM_GUI_H

#include "ofxGui.h"

#include "ofMain.h"

class TransformGui
{
public:
	TransformGui();
	~TransformGui();

	void Setup();
	void Update();
	void Draw();

	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	ofxPanel gui;
};

#endif //TRANSFORM_GUI_H
