#include "ofMain.h"
#include "application.h"

//========================================================================
int main() {
// Param�tres du contexte de rendu OpenGL
	ofGLFWWindowSettings windowSettings;

	windowSettings.width = 1024;
	windowSettings.height = 768;

	// S�lection de la version de OpenGL : Option #1
	// windowSettings.setGLVersion(2,1);

	// S�lection de la version de OpenGL : Option #2
	windowSettings.setGLVersion(3, 3);

	// S�lection de la version de OpenGL : Option #3
	 //windowSettings.setGLVersion(1,4);

	// Cr�ation de la fen�tre
	ofCreateWindow(windowSettings);
	ofRunApp(new Application());

}
