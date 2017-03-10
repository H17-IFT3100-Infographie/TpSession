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

	gui.setup();
	gui.add(createCubeButton.setup("Cube"));
	gui.add(createSphereButton.setup("Sphere"));
	gui.add(createImageButton.setup("Image"));
	gui.add(imageInputField.setup("Filepath:", ""));
	gui.add(createLemniscateButton.setup("Lemniscate"));
}

void Gui::Update()
{

}

void Gui::Draw()
{
	ofBackgroundGradient(ofColor::white, ofColor::gray);

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
