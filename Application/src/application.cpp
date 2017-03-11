// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>

Application::Application()
	: eventEnabled(true)
	, showObjectCreator(true)
{
	renderer = nullptr;
}

Application::~Application()
{
	if (nullptr != renderer)
	{
		delete renderer;
		renderer = nullptr;
	}
		
	if (nullptr != gui)
	{
		gui->GetCreateRectangleButton().removeListener(this, &Application::CreateRectangle);
		gui->GetCreateLineButton().removeListener(this, &Application::CreateLine);
		gui->GetCreateCercleButton().removeListener(this, &Application::CreateCercle);
		gui->GetCreateFVButton().removeListener(this, &Application::CreateFV);
		gui->GetCreateBoxButton().removeListener(this, &Application::CreateBox);
		gui->GetCreateSphereButton().removeListener(this, &Application::CreateSphere);
		gui->GetCreateModelButton().removeListener(this, &Application::CreateModel);
		gui->GetCreateImageButton().removeListener(this, &Application::CreateImage);
		gui->GetCreateLemniscateButton().removeListener(this, &Application::CreateLemniscate);
		gui->GetCreateTetrahedronButton().removeListener(this, &Application::CreateTetrahedron);
		gui->GetShowCamOption().removeListener(this, &Application::ShowCamOptions);

		delete gui;
		gui = nullptr;
	}

	if (nullptr != transformGui)
	{
		delete transformGui;
		transformGui = nullptr;
	}

	if (nullptr != multiTransformGui)
	{
		delete multiTransformGui;
		multiTransformGui = nullptr;
	}

	if (nullptr != cameraGui)
	{
		cameraGui->GetPerspToggle().removeListener(this, &Application::CamToPerspective);
		cameraGui->GetOrhtoToggle().removeListener(this, &Application::CamToOrtho);
		cameraGui->GetFovField().removeListener(this, &Application::SetFOV);
		cameraGui->GetAspectRatio().removeListener(this, &Application::SetAspectRatio);
		cameraGui->GetFarClipping().removeListener(this, &Application::SetFarClippingPlane);
		cameraGui->GetNearClipping().removeListener(this, &Application::SetNearClippingPlane);

		cameraGui->GetObjectCreatorButton().removeListener(this, &Application::ShowObjectsCreator);

		delete cameraGui;
		cameraGui = nullptr;
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

	cameraGui = new CameraGui();
	cameraGui->Setup();
	
	renderer = new Renderer();
	renderer->Setup();
	gui->GetCreateRectangleButton().addListener(this, &Application::CreateRectangle);
	gui->GetCreateLineButton().addListener(this, &Application::CreateLine);
	gui->GetCreateCercleButton().addListener(this, &Application::CreateCercle);
	gui->GetCreateFVButton().addListener(this, &Application::CreateFV);
	gui->GetCreateTetrahedronButton().addListener(this, &Application::CreateTetrahedron);
	gui->GetCreateBoxButton().addListener(this, &Application::CreateBox);
	gui->GetCreateSphereButton().addListener(this, &Application::CreateSphere);
	gui->GetCreateModelButton().addListener(this, &Application::CreateModel);
	gui->GetCreateImageButton().addListener(this, &Application::CreateImage);
	gui->GetCreateLemniscateButton().addListener(this, &Application::CreateLemniscate);
	
	gui->GetShowCamOption().addListener(this, &Application::ShowCamOptions);

	// camera
	cameraGui->GetPerspToggle().addListener(this, &Application::CamToPerspective);
	cameraGui->GetOrhtoToggle().addListener(this, &Application::CamToOrtho);
	cameraGui->GetFovField().addListener(this, &Application::SetFOV);
	cameraGui->GetAspectRatio().addListener(this, &Application::SetAspectRatio);
	cameraGui->GetFarClipping().addListener(this, &Application::SetFarClippingPlane);
	cameraGui->GetNearClipping().addListener(this, &Application::SetNearClippingPlane);

	cameraGui->GetObjectCreatorButton().addListener(this, &Application::ShowObjectsCreator);
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
		if (showObjectCreator)
			gui->Draw();
		else 
			cameraGui->Draw();
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
void Application::CreateTetrahedron()
{
	renderer->CreateTetrahedron();
}
void Application::CreateRectangle() {
	renderer->CreateRectangle();
}
void Application::CreateLine() {
	renderer->CreateLine();
}
void Application::CreateCercle() {
	renderer->CreateCercle();
}
void Application::CreateFV() {
	renderer->CreateFV();
}
void Application::CamToPerspective(const void* sender, bool& pressed)
{
	if (pressed)
	{
		cameraGui->GetOrhtoToggle() = false;
		cameraGui->GetPerspToggle() = true;
		renderer->CamToPerspective();
	}
	else
	{
		cameraGui->GetOrhtoToggle() = true;
		cameraGui->GetPerspToggle() = false;
		renderer->CamToOrtho();
	}
}

void Application::CamToOrtho(const void* sender, bool& pressed)
{
	if (pressed)
	{
		cameraGui->GetOrhtoToggle() = true;
		cameraGui->GetPerspToggle() = false;
		renderer->CamToOrtho();
	}
	else
	{
		cameraGui->GetOrhtoToggle() = false;
		cameraGui->GetPerspToggle() = true;
		renderer->CamToPerspective();
	}
}

void Application::SetFOV(const void* sender, float& value)
{
	renderer->SetFOV(value);
}

void Application::SetAspectRatio(const void* sender, float& value)
{
	renderer->SetAspectRatio(value);
}

void Application::SetFarClippingPlane(const void* sender, float& value)
{
	renderer->SetFarClippingPlane(value);
}

void Application::SetNearClippingPlane(const void* sender, float& value)
{
	renderer->SetNearClippingPlane(value);
}

void Application::ShowCamOptions()
{
	cameraGui->GetFovField().SetValue(renderer->GetFOV());
	cameraGui->GetAspectRatio().SetValue(renderer->GetAspectRatio());
	cameraGui->GetFarClipping().SetValue(renderer->GetFarClippingPlane());
	cameraGui->GetNearClipping().SetValue(renderer->GetNearClippingPlane());

	showObjectCreator = false;
}

void Application::ShowObjectsCreator()
{
	showObjectCreator = true;
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
