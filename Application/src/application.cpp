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
		gui->GetCreateModelButton().removeListener(this, &Application::CreateModel);
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

	multiTransformGui = new MultiTransformGui();
	multiTransformGui->Setup();

	renderer = new Renderer();
	renderer->Setup();

	gui->GetCreateBoxButton().addListener(this, &Application::CreateBox);
	gui->GetCreateSphereButton().addListener(this, &Application::CreateSphere);
	gui->GetCreateModelButton().addListener(this, &Application::CreateModel);
	gui->GetCreateImageButton().addListener(this, &Application::CreateImage);
	gui->GetCreateLemniscateButton().addListener(this, &Application::CreateLemniscate);
}

void Application::update()
{
	if (renderer->IsAnyObjectSelected())
	{
		if (renderer->ObjectsSelectedCount() == 1)
		{
			eventEnabled = !transformGui->IsAnyGuiFocused();
			transformGui->Update(renderer->GetCurrentSelectedObjects()[0]);
		}
		else
		{
			eventEnabled = !multiTransformGui->IsAnyGuiFocused();
			multiTransformGui->Update(renderer->GetCurrentSelectedObjects());
		}
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
		if (renderer->ObjectsSelectedCount() == 1)
		{
			transformGui->Draw();
		}
		else
		{
			multiTransformGui->Draw();
		}
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

void Application::CreateModel()
{
	renderer->CreateModel("Lara_Croft/Lara_Croft.obj");
/*const std::string& filepath(gui->GetImageInputField().GetValue());
	if (ofFile::doesFileExist(filepath))
	{
		renderer->CreateModel(filepath);
	}
	else
	{
		// Show error?
	}
	gui->GetImageInputField().leaveFocus();
	gui->GetImageInputField().ResetValue();*/
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
			if (renderer->SelectObject(index) && renderer->ObjectsSelectedCount() == 1)
			{
				transformGui->OnSelected(renderer->GetCurrentSelectedObjects()[0]);
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
