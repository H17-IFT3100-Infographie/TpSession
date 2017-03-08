// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>

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

void Application::update()
{
	//gui->Update();
	renderer->Update();
}

void Application::draw()
{
	//gui->Draw();
	renderer->Draw();
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

void Application::keyPressed(int key)
{
	if (key == 'x')
	{
		time_t timev;
		time(&timev);

		ofImage img;
		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		img.save("screenshot_" + boost::lexical_cast<std::string>(timev) + ".png");

		return;
	}

	renderer->KeyPressed(key);
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
