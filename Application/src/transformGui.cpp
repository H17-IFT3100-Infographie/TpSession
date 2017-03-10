#include "transformGui.h"

TransformGui::TransformGui()
{
}

TransformGui::~TransformGui()
{
}

void TransformGui::Setup()
{
	ofSetVerticalSync(true);

	// we add this listener before setting up so the initial circle resolution is correct
	//circleResolution.addListener(this, &Application::circleResolutionChanged);
	//ringButton.addListener(this, &Application::ringButtonPressed);

	gui.setup(); // most of the time you don't need a name
}

void TransformGui::Update()
{

}

void TransformGui::Draw()
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

void TransformGui::windowResized(int w, int h)
{

}

void TransformGui::dragEvent(ofDragInfo dragInfo)
{

}

void TransformGui::gotMessage(ofMessage msg)
{

}
