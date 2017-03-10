#include "gui.h"

Gui::Gui()
	: BaseGui()
{
}

Gui::~Gui()
{
}

void Gui::Setup()
{
	BaseGui::Setup();
	gui.setup();
	gui.add(createCubeButton.setup("Cube"));
	gui.add(createSphereButton.setup("Sphere"));
	gui.add(createImageButton.setup("Image"));
	gui.add(createModelButton.setup("Model"));

	gui.add(imageInputField.setup("Filepath:", ""));

	gui.add(createLemniscateButton.setup("Lemniscate"));
}

bool Gui::IsAnyGuiFocused()
{
	return imageInputField.IsFocus();
}
