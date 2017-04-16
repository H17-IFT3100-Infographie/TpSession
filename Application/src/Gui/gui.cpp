#include "gui.h"
// Constructeur de la classe Gui sans paramètre
Gui::Gui()
	: BaseGui()
{
}
// Destructeur de la classe Gui
Gui::~Gui()
{
}
// Fonction permettant l'initialisation de l'interface graphique
void Gui::Setup()
{
	BaseGui::Setup();
	// Initialisation des options de l'interface graphique
	gui.setup();
	// Options permettant la génération de primitives 2d
	gui.add(createRectButton.setup("Rectangle"));
	gui.add(createLineButton.setup("Line"));
	gui.add(createCercleButton.setup("Cercle"));
	gui.add(createFVButton.setup("Forme Vectorielle"));
	// Options permettant la génération de primitives 3d 
	gui.add(createCubeButton.setup("Cube"));
	gui.add(createSphereButton.setup("Sphere"));
	gui.add(createOctahedreButton.setup("Octahedre"));
	// Options permettant le chargement de modèles et d'images
	gui.add(createModelButton.setup("Model"));
	gui.add(createImageButton.setup("Image"));
	gui.add(imageInputField.setup("Filepath:", ""));
	// Option permettant le rendu d'une image procédurale
	gui.add(createLemniscateButton.setup("Lemniscate"));

	gui.add(createDirectionalLight.setup("Directional Light"));
	gui.add(createAmbiantLight.setup("Ambiant Light"));
	gui.add(createSpotLight.setup("Spot Light"));
	gui.add(createPointLight.setup("Point Light"));

	gui.add(material1Toggle.setup("Material 1", false));
	gui.add(material2Toggle.setup("Material 2", false));
	gui.add(material3Toggle.setup("Material 3", false));


	// Option permettant de passer à l'interface de la caméra
	gui.add(gotoCamOptions.setup("Camera Options"));
}
// Fonction permettant de savoir si l'interface est en usage
bool Gui::IsAnyGuiFocused()
{
	return imageInputField.IsFocus();
}
