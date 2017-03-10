// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>

Application::Application()
{
	renderer = nullptr;
}

Application::~Application()
{
	if (nullptr != renderer)
	{
		delete renderer;
	}
		
	if (nullptr != gui)
	{
		gui->GetCreateBoxButton().removeListener(this, &Application::CreateBox);
		delete gui;
	}

	if (nullptr != transformGui)
	{
		delete transformGui;
	}

		
}

void Application::setup()
{
	ofSetWindowTitle("IFT3100 - TpSession");

	ofLog() << "<app::setup>";

	gui = new Gui();
	gui->Setup();

	transformGui = new TransformGui();
	transformGui->Setup();

	renderer = new Renderer();
	renderer->Setup();

	gui->GetCreateBoxButton().addListener(this, &Application::CreateBox);
}

void Application::update()
{
	if (renderer->IsAnyObjectSelected())
	{
		transformGui->Update();
	}
	else
	{
		gui->Update();
	}
	
	renderer->Update();
}

void Application::draw()
{
	if (renderer->IsAnyObjectSelected())
	{
		transformGui->Draw();
	}
	else
	{
		gui->Draw();
	}
	renderer->Draw();
}

void Application::CreateBox()
{
	renderer->CreateBox();
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

void Application::mouseReleased(int x, int y, int button)
{
	renderer->MouseRelease(x, y, button);
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

void Application::keyReleased(int key)
{
	renderer->keyReleased(key);
}

void Application::exit()
{
	ofLog() << "<app::exit>";
}
