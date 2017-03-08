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

	ofLog() << "<app::setup>";

	//gui = new Gui();
	//gui->Setup();

	renderer = new Renderer();
	renderer->Setup();
}

void Application::draw()
{
	//gui->Draw();
	renderer->Draw();
}

void Application::update()
{
	//gui->Update();
}

void Application::mousePressed(int x, int y, int button)
{
	renderer->MousePressed(x, y, button);
}

void Application::mouseDragged(int x, int y, int button)
{
	renderer->MouseDragged(x, y, button);
}

void Application::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	renderer->MouseScrolled(x, y, scrollX, scrollY);
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
