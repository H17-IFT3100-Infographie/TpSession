#include "gui.h"

BaseGui::BaseGui()
	: pos(ofVec2f::zero())
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
	gui.setPosition(pos.x, pos.y);
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