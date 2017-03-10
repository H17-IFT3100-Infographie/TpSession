// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>

Application::Application()
	: eventEnabled(true)
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
		gui->GetCreateSphereButton().removeListener(this, &Application::CreateSphere);
		gui->GetCreateImageButton().removeListener(this, &Application::CreateImage);
		gui->GetCreateLemniscateButton().removeListener(this, &Application::CreateLemniscate);
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
	gui->GetCreateSphereButton().addListener(this, &Application::CreateSphere);
	gui->GetCreateImageButton().addListener(this, &Application::CreateImage);
	gui->GetCreateLemniscateButton().addListener(this, &Application::CreateLemniscate);
}

void Application::update()
{
	if (renderer->IsAnyObjectSelected())
	{
		eventEnabled = !transformGui->IsAnyGuiFocused();
		transformGui->Update(renderer->GetCurrentSelectedObject());
	}
	else
	{
		eventEnabled = !gui->IsAnyGuiFocused();
		gui->Update();
	}

	if (!eventEnabled)
	{
		renderer->HideAllCustomCursors();
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

void Application::CreateSphere()
{
	renderer->CreateSphere();
}

void Application::CreateImage()
{
	const std::string& filepath(gui->GetImageInputField().GetValue());
	if (ofFile::doesFileExist(filepath))
	{
		renderer->CreateImage(filepath);
	}
	else
	{
		// Show error?
	}
	gui->GetImageInputField().leaveFocus();
	gui->GetImageInputField().ResetValue();
}

void Application::CreateLemniscate()
{
	renderer->CreateLemniscate();
}

void Application::mousePressed(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MousePressed(x, y, button);
	}
}

void Application::mouseDragged(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MouseDragged(x, y, button);
	}
}

void Application::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	if (eventEnabled)
	{
		renderer->MouseScrolled(x, y, scrollX, scrollY);
	}
}

void Application::mouseReleased(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MouseRelease(x, y, button);
	}
}

void Application::keyPressed(int key)
{
	if (eventEnabled)
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

		int index = -1;
		switch (key)
		{
		case '1':
			index = 0;
			break;
		case '2':
			index = 1;
			break;
		case '3':
			index = 2;
			break;
		case '4':
			index = 3;
			break;
		case '5':
			index = 4;
			break;
		case '6':
			index = 5;
			break;
		case '7':
			index = 6;
			break;
		}

		if (index != -1)
		{
			if (renderer->SelectObject(index))
			{
				transformGui->OnSelected(renderer->GetCurrentSelectedObject());
			}
		}

		renderer->KeyPressed(key);
	}
}

void Application::keyReleased(int key)
{
	if (eventEnabled)
	{
		renderer->keyReleased(key);
	}
}

void Application::exit()
{
	ofLog() << "<app::exit>";
}
