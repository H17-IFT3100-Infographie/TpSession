#include "ofMain.h"
#include "application.h"

//========================================================================
int main() {
// Paramètres du contexte de rendu OpenGL
	ofGLFWWindowSettings windowSettings;

	windowSettings.width = 1024;
	windowSettings.height = 768;

	// Sélection de la version de OpenGL : Option #1
	// windowSettings.setGLVersion(2,1);

	// Sélection de la version de OpenGL : Option #2
	windowSettings.setGLVersion(3, 3);

	// Sélection de la version de OpenGL : Option #3
	 //windowSettings.setGLVersion(1,4);

	// Création de la fenêtre
	ofCreateWindow(windowSettings);
	ofRunApp(new Application());

}
