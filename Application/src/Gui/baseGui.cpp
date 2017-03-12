#include "gui.h"
// Constructeur de la classe BaseGui sans paramètre
BaseGui::BaseGui()
	: pos(ofVec2f::zero())
{
}
// Destructeur de la classe BaseGui
BaseGui::~BaseGui()
{
}
// Fonction permettant la mise à jour de BaseGui
void BaseGui::Setup()
{
	// Initialisation de la synchronisation verticale
	ofSetVerticalSync(true);
}
// Fonction permettant la mise à jour de la BaseGui
void BaseGui::Update(BaseObject* currentObjectSelected)
{

}
// Fonction permettant le rendu de la BaseGui
void BaseGui::Draw()
{
	// Paramétrage et affichage de l'interface
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	gui.setPosition(pos.x, pos.y);
	gui.draw();
}
// Fonction permettant l'ajustement de la fenêtre sur redimensionnement
void BaseGui::windowResized(int w, int h)
{
	// TODO
}

void BaseGui::dragEvent(ofDragInfo dragInfo)
{
	//TODO
}

void BaseGui::gotMessage(ofMessage msg)
{
	//TODO
}