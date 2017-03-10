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
	gui.add(createModelButton.setup("Model"));
	gui.add(createImageButton.setup("Image"));
	gui.add(imageInputField.setup("Filepath:", ""));
	gui.add(createLemniscateButton.setup("Lemniscate"));

	gui.add(gotoCamOptions.setup("Camera Options"));
}

bool Gui::IsAnyGuiFocused()
{
	return imageInputField.IsFocus();
}
