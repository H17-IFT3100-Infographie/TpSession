#ifndef BASE_GUI_H
#define BASE_GUI_H

#include "ofxGui.h"
#include "ofMain.h"

#include "Objects/baseObject.h"

class BaseGui
{
public:
	BaseGui();
	~BaseGui();

	virtual void Setup();
	virtual void Update(BaseObject* currentObjectSelected = nullptr);
	virtual void Draw();

	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	virtual bool IsAnyGuiFocused() { return false; }

protected:
	ofxPanel gui;
	ofVec2f pos;
private:
};

#endif //BASE_GUI_H
