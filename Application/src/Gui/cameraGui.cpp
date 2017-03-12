#include "cameraGui.h"
// Constructeur de la classe CameraGui sans param�tre
CameraGui::CameraGui()
	: BaseGui()
{
	pos = ofVec3f(0.0f, 0.0f);
}
// Destructeur de la classe CameraGui
CameraGui::~CameraGui()
{
}
// Fonction permettant l'initialisation de l'interface de la cam�ra
void CameraGui::Setup()
{
	BaseGui::Setup();
	// Initialisation de l'interface de la cam�ra
	gui.setup();
	// Param�tres li�s � la projection
	gui.add(perspToggle.setup("Perspective", true));
	gui.add(orthoToggle.setup("Orthographic", false));
	// Param�tres li�s au champ de vision et aux plans avant/arri�re
	gui.add(fovField.setup("FOV", 60, 0, 300));
	gui.add(aspectRatio.setup("Aspect Ratio", 1.33f, 0, 2.0f));
	gui.add(farClipping.setup("Far", 2000, 0, 3000));
	gui.add(nearClipping.setup("Near", 0, 0, 3000));
	// Bouton permettant l'affichage d'un quadrillage
	gui.add(gridActivatorToggle.setup("Show Grid", true));
	// Bouton permettant de passer aux options de cr�ation d'objets
	gui.add(showObjectsCreator.setup("Objects Creator"));
}
