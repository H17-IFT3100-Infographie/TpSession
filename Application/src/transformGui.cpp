#include "transformGui.h"

TransformGui::TransformGui()
	: posIsDirty(false)
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
	gui.add(posXField.setup("PosX:", 0));
	gui.add(posYField.setup("PosY:", 0));
	gui.add(posZField.setup("PosZ:", 0));
}

void TransformGui::Update(BaseObject* currentObjectSelected)
{
	if (currentObjectSelected != nullptr)
	{
		if (posXField.IsDirty())
			currentObjectSelected->pos.x = posXField.GetValue();

		if (posYField.IsDirty())
			currentObjectSelected->pos.y = posYField.GetValue();

		if (posZField.IsDirty())
			currentObjectSelected->pos.z = posZField.GetValue();

		ofVec3f pos = currentObjectSelected->pos;

		if (!posXField.IsFocus())
			posXField.SetValue(pos.x);

		if (!posYField.IsFocus())
			posYField.SetValue(pos.y);

		if (!posZField.IsFocus())
			posZField.SetValue(pos.z);
	}
	else
	{
		posXField.SetValue(-1);
		posYField.SetValue(-1);
		posZField.SetValue(-1);
	}
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

void TransformGui::PosEntered()
{
	posIsDirty = true;
}