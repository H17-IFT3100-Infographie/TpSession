// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>

Application* Application::instance = 0;

// Constructeur pour l'application, pr�sentant l'interface de cr�ation d'objets
Application::Application()
	: eventEnabled(true)
	, showObjectCreator(true)
{
	instance = this;
	renderer = nullptr;
}
// Destructeur pour la classe application
Application::~Application()
{
	// On d�truit les diff�rents gui	
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
		gui->GetCreateOctahedreButton().removeListener(this, &Application::CreateIcosahedron);
		gui->GetCreateCubeMap().removeListener(this, &Application::CreateCubeMap);
		gui->GetCreateQuadratic().removeListener(this, &Application::CreateQuadratic);
		gui->GetCreateCubic().removeListener(this, &Application::CreateCubic);
		gui->GetCreateHermite().removeListener(this, &Application::CreateHermite);
		gui->GetCreateBSpline().removeListener(this, &Application::CreateBSpline);

		gui->GetCreateSurface().removeListener(this, &Application::CreateSurface);

		gui->GetCreateDirectionalLight().removeListener(this, &Application::CreateDirectionalLight);
		gui->GetCreatePointLight().removeListener(this, &Application::CreatePointLight);
		gui->GetCreateAmbiantLight().removeListener(this, &Application::CreateAmbiantLight);
		gui->GetCreateSpotLight().removeListener(this, &Application::CreateSpotLight);
		gui->GetMaterial1Toggle().removeListener(this, &Application::SetMaterial1);
		gui->GetMaterial2Toggle().removeListener(this, &Application::SetMaterial2);
		gui->GetMaterial3Toggle().removeListener(this, &Application::SetMaterial3);
		gui->GetShowCamOption().removeListener(this, &Application::ShowCamOptions);

		delete gui;
		gui = nullptr;
	}
	// On d�truit le gui des transformations
	if (nullptr != transformGui)
	{
		delete transformGui;
		transformGui = nullptr;
	}
	// On d�truit le gui des transformations sur plusieurs �l�ments 
	if (nullptr != multiTransformGui)
	{
		delete multiTransformGui;
		multiTransformGui = nullptr;
	}
	// On d�truit le gui de la cam�ra
	if (nullptr != cameraGui)
	{
		cameraGui->GetPerspToggle().removeListener(this, &Application::CamToPerspective);
		cameraGui->GetOrhtoToggle().removeListener(this, &Application::CamToOrtho);
		cameraGui->GetFovField().removeListener(this, &Application::SetFOV);
		cameraGui->GetAspectRatio().removeListener(this, &Application::SetAspectRatio);
		cameraGui->GetFarClipping().removeListener(this, &Application::SetFarClippingPlane);
		cameraGui->GetNearClipping().removeListener(this, &Application::SetNearClippingPlane);
		cameraGui->GetGridActivatorToggle().removeListener(this, &Application::SetGridActivated);
		cameraGui->GetObjectCreatorButton().removeListener(this, &Application::ShowObjectsCreator);

		delete cameraGui;
		cameraGui = nullptr;
	}

	// On d�truit le renderer
	if (nullptr != renderer)
	{
		delete renderer;
		renderer = nullptr;
	}
}
// Initialisation de l'application
void Application::setup()
{
	ofSetWindowTitle("IFT3100 - TpSession");

	// On g�n�re le renderer, responsable du rendu graphique de la sc�ne
	renderer = new Renderer();
	if (ofIsGLProgrammableRenderer())
	{

		renderer->glVersionMajor = 3;
		renderer->glVersionMinor = 3;
	}


	else
	{
		renderer->glVersionMajor = 2;
		renderer->glVersionMinor = 1;
	}

	material = new ofMaterial();
	renderer->Setup();

	// On g�n�re le gui
	gui = new Gui();
	gui->Setup();
	// On g�n�re le gui responsable des transformations
	transformGui = new TransformGui();
	transformGui->Setup();

	multiTransformGui = new MultiTransformGui();
	multiTransformGui->Setup();
	// On g�n�re le gui responsable des options de la cam�ra
	cameraGui = new CameraGui();
	cameraGui->Setup();

	// Ajoute des listeners pour valider les clics des boutons de l'interface Cr�ation d'objets
	gui->GetCreateRectangleButton().addListener(this, &Application::CreateRectangle);
	gui->GetCreateLineButton().addListener(this, &Application::CreateLine);
	gui->GetCreateCercleButton().addListener(this, &Application::CreateCercle);
	gui->GetCreateFVButton().addListener(this, &Application::CreateFV);
	gui->GetCreateOctahedreButton().addListener(this, &Application::CreateIcosahedron);
	gui->GetCreateBoxButton().addListener(this, &Application::CreateBox);
	gui->GetCreateSphereButton().addListener(this, &Application::CreateSphere);
	gui->GetCreateModelButton().addListener(this, &Application::CreateModel);
	gui->GetCreateImageButton().addListener(this, &Application::CreateImage);
	gui->GetCreateLemniscateButton().addListener(this, &Application::CreateLemniscate);
	gui->GetCreateCubeMap().addListener(this, &Application::CreateCubeMap);
	gui->GetCreateQuadratic().addListener(this, &Application::CreateQuadratic);
	gui->GetCreateCubic().addListener(this, &Application::CreateCubic);
	gui->GetCreateHermite().addListener(this, &Application::CreateHermite);
	gui->GetCreateBSpline().addListener(this, &Application::CreateBSpline);

	gui->GetCreateSurface().addListener(this, &Application::CreateSurface);

	gui->GetCreateDirectionalLight().addListener(this, &Application::CreateDirectionalLight);
	gui->GetCreatePointLight().addListener(this, &Application::CreatePointLight);
	gui->GetCreateAmbiantLight().addListener(this, &Application::CreateAmbiantLight);
	gui->GetCreateSpotLight().addListener(this, &Application::CreateSpotLight);

	gui->GetMaterial1Toggle().addListener(this, &Application::SetMaterial1);
	gui->GetMaterial2Toggle().addListener(this, &Application::SetMaterial2);
	gui->GetMaterial3Toggle().addListener(this, &Application::SetMaterial3);


	gui->GetShowCamOption().addListener(this, &Application::ShowCamOptions);

	// Ajout des listeners pour valider les clics des boutons de l'interface Cam�ra 
	cameraGui->GetPerspToggle().addListener(this, &Application::CamToPerspective);
	cameraGui->GetOrhtoToggle().addListener(this, &Application::CamToOrtho);
	cameraGui->GetFovField().addListener(this, &Application::SetFOV);
	cameraGui->GetAspectRatio().addListener(this, &Application::SetAspectRatio);
	cameraGui->GetFarClipping().addListener(this, &Application::SetFarClippingPlane);
	cameraGui->GetNearClipping().addListener(this, &Application::SetNearClippingPlane);
	cameraGui->GetGridActivatorToggle().addListener(this, &Application::SetGridActivated);
	
	cameraGui->GetObjectCreatorButton().addListener(this, &Application::ShowObjectsCreator);



}
// Fonction de mise � jour de l'application
void Application::update()
{
	// Validation de la position en X de la souris
	ofGetMouseX() > 200 ? eventEnabled = true : eventEnabled = false;

	// On met � jour le rendu et les transformations pour les objets s�lectionn�s
	if (renderer->IsAnyObjectSelected())
	{
		if (renderer->ObjectsSelectedCount() == 1)
		{
			transformGui->Update(renderer->GetCurrentSelectedObjects()[0]);
		}
		else
		{
			multiTransformGui->Update(renderer->GetCurrentSelectedObjects());
		}
	}
	// Si aucun �l�ment n'est s�lectionn�, on met � jour le gui
	else
	{
		gui->Update();
	}

	if (!eventEnabled)
	{
		renderer->HideAllCustomCursors();
	}
	// Mise � jour du renderer
	renderer->Update();
}
// Fonction permettant l'affichage de l'application et du rendu
void Application::draw()
{
	// Validation des �l�ments s�lectionn�s pour mise � jour de leur rendu
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
	// Sinon, on affiche le gui courant : Object creator ou cameraGui
	else
	{
		if (showObjectCreator)
			gui->Draw();
		else 
			cameraGui->Draw();
	}
	// On appelle la fonction de dessin du renderer pour le rendu
	renderer->Draw();

}

// Fonction appelant la m�thode CreateBox du renderer
void Application::CreateBox()
{
	renderer->CreateBox();
}

// Fonction appelant la m�thode CreateSphere du renderer
void Application::CreateSphere()
{
	renderer->CreateSphere();
}

// Fonction appelant la m�thode CreateModel du renderer
void Application::CreateModel()
{
	renderer->CreateModel("MegaMan/MegaMan_OpenCollada.DAE");
}

// Fonction permettant l'appel de la m�thode CreateImage de la classe Renderer
void Application::CreateImage()
{
	// On r�cup�re le nom du fichier contenu dans la textbox Filepath
	const std::string& filepath(gui->GetImageInputField().GetValue());
	// Si le fichier existe, on appelle la fonction du renderer pour cr�er l'image
	if (!filepath.empty() && ofFile::doesFileExist(filepath))
	{
		renderer->CreateImage(filepath);
	}
	else
	{
		// Show error?
	}
	// R�initialisation de la textbox
	gui->GetImageInputField().leaveFocus();
	gui->GetImageInputField().ResetValue();
}
// Fonction appelant la m�thode CreateLemniscate du renderer
void Application::CreateLemniscate()
{
	renderer->CreateLemniscate();
}
// Fonction appelant la m�thode CreateIcosahedron du renderer
void Application::CreateIcosahedron()
{
	renderer->CreateIcosahedron();
}
// Fonction appelant la m�thode CreateRectangle du renderer
void Application::CreateRectangle() 
{
	renderer->CreateRectangle();
}
// Fonction appelant la m�thode CreateLine du renderer
void Application::CreateLine() 
{
	renderer->CreateLine();
}
// Fonction appelant la m�thode CreateCercle du renderer
void Application::CreateCercle() 
{
	renderer->CreateCercle();
}
// Fonction appelant la m�thode CreateFV du renderer
void Application::CreateFV()
{
	renderer->CreateFV();
}

void Application::CreateQuadratic()
{
	renderer->CreateQuadratic();
}
void Application::CreateCubeMap()
{
renderer->CreateCubeMap();
}
void Application::CreateCubic()
{
	renderer->CreateCubic();
}

void Application::CreateHermite()
{
	renderer->CreateHermite();
}

void Application::CreateBSpline()
{
	renderer->CreateBSpline();
}

void Application::CreateSurface()
{
	renderer->CreateSurface();
}

void Application::CreateDirectionalLight()
{
	renderer->CreateDirectionalLight();
}

void Application::CreateAmbiantLight()
{
	renderer->CreateAmbiantLight();
}

void Application::CreateSpotLight()
{
	renderer->CreateSpotLight();
}

void Application::CreatePointLight()
{
	renderer->CreatePointLight();
}

// Fonction permettant de mettre la vision de la cam�ra en projection en perspective
void Application::CamToPerspective(const void* sender, bool& pressed)
{
	// Si cliqu�, Perspective est en fonction, sinon c'est le mode projection orthogonale
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
// Fonction permettant de mettre la vision de la cam�ra en projection orthogonale
void Application::CamToOrtho(const void* sender, bool& pressed)
{
	// Si cliqu�, orthogonale, sinon perspective
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
// Fonction appelant la m�thode du renderer permettant de modifier l'angle d'ouverture du champ de vision
void Application::SetFOV(const void* sender, float& value)
{
	renderer->SetFOV(value);
}
// Fonction appelant la m�thode du renderer permettant de modifier le ratio d'aspect
void Application::SetAspectRatio(const void* sender, float& value)
{
	renderer->SetAspectRatio(value);
}
// Fonction appelant la m�thode du renderer permettant de modifier la valeur du plan de clipping arri�re
void Application::SetFarClippingPlane(const void* sender, float& value)
{
	renderer->SetFarClippingPlane(value);
}
// Fonction appelant la m�thode du renderer permettant de modifier la valeur du plan de clipping avanc�
void Application::SetNearClippingPlane(const void* sender, float& value)
{
	renderer->SetNearClippingPlane(value);
}
// Activation du grid dans le viewport
void Application::SetGridActivated(const void* sender, bool& pressed)
{
	cameraGui->GetGridActivatorToggle() = pressed;
	renderer->SetGridActivated(pressed);
}

// Fonction permettant l'affichage des options de la cam�ra
void Application::ShowCamOptions()
{
	cameraGui->GetFovField().SetValue(renderer->GetFOV());
	cameraGui->GetAspectRatio().SetValue(renderer->GetAspectRatio());
	cameraGui->GetFarClipping().SetValue(renderer->GetFarClippingPlane());
	cameraGui->GetNearClipping().SetValue(renderer->GetNearClippingPlane());

	showObjectCreator = false;
}
// Fonction permettant de pr�senter le menu gui associ� � la cr�ation d'objets
void Application::ShowObjectsCreator()
{
	showObjectCreator = true;
}
// Fonction envoyant au renderer l'information des boutons de la souris cliqu�s
void Application::mousePressed(int x, int y, int button)
{
	if (eventEnabled)
	{
		if (renderer->MousePressed(x, y, button))
			transformGui->OnSelected(renderer->GetCurrentSelectedObjects()[0]);
	}
}
// Fonction envoyant au renderer l'information sur le drag de la souris
void Application::mouseDragged(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MouseDragged(x, y, button);
	}
}
// Fonction envoyant au renderer l'information sur le scroll de la souris
void Application::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
	if (eventEnabled)
	{
		renderer->MouseScrolled(x, y, scrollX, scrollY);
	}
}
// Fonction envoyant au renderer l'information sur les boutons rel�ch�s de la souris
void Application::mouseReleased(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MouseRelease(x, y, button);
	}
}
// Fonction permettant la gestion des touches du clavier enfonc�es
void Application::keyPressed(int key)
{
	if (eventEnabled)
	{
		// La touche x permet de sauvegarder l'image de la sc�ne actuelle sur le disque dur
		if (key == 'x')
		{
			time_t timev;
			time(&timev);

			ofImage img;
			img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img.save("screenshot_" + boost::lexical_cast<std::string>(timev) + ".png");

			return;
		}

		// On retourne au renderer la touche appuy�e pour gestion de contr�les.
		renderer->KeyPressed(key);
	}
}
// Fonction envoyant au renderer l'information concernant les touches clavier rel�ch�es
void Application::keyReleased(int key)
{
	switch (key)
	{
	case 'c':  // key c
		renderer->activeShader = Shading::COLOR_FILL;
		ofLog() << "<shader: Color Fill>";
		break;

	case 'l':  // key l
		renderer->activeShader = Shading::LAMBERT;
		ofLog() << "<shader: Lambert>";
		break;

	case 'g':  // key g
		renderer->activeShader = Shading::GOURAUD;
		ofLog() << "<shader: Gouraud>";
		break;

	case 'p':  // key p
		renderer->activeShader = Shading::PHONG;
		ofLog() << "<shader: Phong>";
		break;

	case 'b':  // key b
		renderer->activeShader = Shading::BLINN_PHONG;
		ofLog() << "<shader: Blinn-Phong>";
		break;

	case 'r':  // key r
		renderer->activeShader = Shading::REFLECTIVE;
		ofLog() << "<shader: Reflective>";
		break;
	}

	if (eventEnabled)
	{
		renderer->keyReleased(key);
	}
}
void Application::SetMaterial1(const void* sender, bool& pressed)
{
// Si cliqu�, Material 1
if (pressed)
{
	gui->GetMaterial1Toggle() = true;
	gui->GetMaterial2Toggle() = false;
	gui->GetMaterial3Toggle() = false;
	material->setDiffuseColor(0.5f);
	material->setAmbientColor(0.1f);
	material->setEmissiveColor(0.0f);
	material->setSpecularColor(0.0f);
	material->setShininess(2);
}
}
void Application::SetMaterial2(const void* sender, bool& pressed)
{
	// Si cliqu�, Material 2
	if (pressed)
	{
		gui->GetMaterial2Toggle() = true;
		gui->GetMaterial1Toggle() = false;
		gui->GetMaterial3Toggle() = false;
		material->setDiffuseColor(ofFloatColor::magenta);
		material->setAmbientColor(0.5f);
		material->setEmissiveColor(0.7f);
		material->setSpecularColor(0.7f);
		material->setShininess(1);
	}
}

void Application::SetMaterial3(const void* sender, bool& pressed) 
{
	// Si cliqu�, Material 3
	if (pressed)
	{
		gui->GetMaterial3Toggle() = true;
		gui->GetMaterial1Toggle() = false;
		gui->GetMaterial2Toggle() = false;
		material->setDiffuseColor(0.1f);
		material->setAmbientColor(0.4f);
		material->setEmissiveColor(ofFloatColor::blue);
		material->setSpecularColor(0.9f);
		material->setShininess(5);
	}
}

void Application::exit()
{

}
