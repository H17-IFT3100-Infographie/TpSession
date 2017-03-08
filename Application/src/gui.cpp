#include "gui.h"

Gui::Gui()
{
}

Gui::~Gui()
{
}

void Gui::Setup()
{
	ofSetVerticalSync(true);

	// we add this listener before setting up so the initial circle resolution is correct
	//circleResolution.addListener(this, &Application::circleResolutionChanged);
	//ringButton.addListener(this, &Application::ringButtonPressed);

	gui.setup(); // most of the time you don't need a name
	gui.add(filled.setup("fill", true));
	gui.add(radius.setup("radius", 140, 10, 300));
	gui.add(center.setup("center", ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
	gui.add(circleResolution.setup("circle res", 5, 3, 90));
	gui.add(twoCircles.setup("two circles"));
	gui.add(ringButton.setup("ring"));
	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));
}

void Gui::Update()
{

}

void Gui::Draw()
{
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	if (filled) {
		ofFill();
	}
	else {
		ofNoFill();
	}

	ofSetColor(color);
	if (twoCircles) {
		ofDrawCircle(center->x - radius*.5, center->y, radius);
		ofDrawCircle(center->x + radius*.5, center->y, radius);
	}
	else {
		ofDrawCircle((ofVec2f)center, radius);
	}

	gui.draw();
}

void Gui::windowResized(int w, int h)
{

}

void Gui::dragEvent(ofDragInfo dragInfo)
{

}

void Gui::gotMessage(ofMessage msg)
{

}
