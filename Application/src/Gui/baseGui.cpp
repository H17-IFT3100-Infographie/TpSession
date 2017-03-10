#include "gui.h"

BaseGui::BaseGui()
{
}

BaseGui::~BaseGui()
{
}

void BaseGui::Setup()
{
	ofSetVerticalSync(true);
}

void BaseGui::Update(BaseObject* currentObjectSelected)
{

}

void BaseGui::Draw()
{
	ofBackgroundGradient(ofColor::white, ofColor::gray);

	gui.draw();
}

void BaseGui::windowResized(int w, int h)
{

}

void BaseGui::dragEvent(ofDragInfo dragInfo)
{

}

void BaseGui::gotMessage(ofMessage msg)
{

}