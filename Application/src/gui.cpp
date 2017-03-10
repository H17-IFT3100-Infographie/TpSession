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
	gui.add(createCubeButton.setup("Cube"));
}

void Gui::Update()
{

}

void Gui::Draw()
{
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	/*if (filled) {
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
	}*/

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
