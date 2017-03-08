// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
	renderer = nullptr;
}

void Application::setup()
{
	ofSetWindowTitle("IFT3100 - TpSession");

	//ofLog() << "<app::setup>";

	renderer = new Renderer();
	renderer->setup();
}

void Application::draw()
{
	renderer->draw();
}

// fonction invoquée quand une touche du clavier est relâchée
void Application::keyReleased(int key)
{
	switch (key)
	{
	case OF_KEY_LEFT:
		renderer->LeftArrowPressed();
		break;
	case OF_KEY_RIGHT:
		renderer->RightArrowPressed();
		break;
	default:
		break;
	}
}

void Application::exit()
{
	ofLog() << "<app::exit>";
}

Application::~Application()
{
	if (nullptr != renderer)
		delete renderer;
}
