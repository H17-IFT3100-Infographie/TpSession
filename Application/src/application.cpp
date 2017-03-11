// Classe principale de l'application.

#include "application.h"

#include <boost/lexical_cast.hpp>
// Constructeur pour l'application, présentant l'interface de création d'objets
Application::Application()
	: eventEnabled(true)
	, showObjectCreator(true)
{
	renderer = nullptr;
}
// Destructeur pour la classe application
Application::~Application()
{
	// On détruit le renderer
	if (nullptr != renderer)
	{
		delete renderer;
		renderer = nullptr;
	}
	// On détruit les différents gui	
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
	// On détruit le gui des transformations
	if (nullptr != transformGui)
	{
		delete transformGui;
		transformGui = nullptr;
	}
	// On détruit le gui des transformations sur plusieurs éléments 
	if (nullptr != multiTransformGui)
	{
		delete multiTransformGui;
		multiTransformGui = nullptr;
	}
	// On détruit le gui de la caméra
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
// Initialisation de l'application
void Application::setup()
{
	ofSetWindowTitle("IFT3100 - TpSession");

	ofLog() << "<app::setup>";
	// On génère le gui
	gui = new Gui();
	gui->Setup();
	// On génère le gui responsable des transformations
	transformGui = new TransformGui();
	transformGui->Setup();

	multiTransformGui = new MultiTransformGui();
	multiTransformGui->Setup();
	// On génère le gui responsable des options de la caméra
	cameraGui = new CameraGui();
	cameraGui->Setup();
	// On génère le renderer, responsable du rendu graphique de la scène
	renderer = new Renderer();
	renderer->Setup();

	// Ajoute des listeners pour valider les clics des boutons de l'interface Création d'objets
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

	// Ajout des listeners pour valider les clics des boutons de l'interface Caméra 
	cameraGui->GetPerspToggle().addListener(this, &Application::CamToPerspective);
	cameraGui->GetOrhtoToggle().addListener(this, &Application::CamToOrtho);
	cameraGui->GetFovField().addListener(this, &Application::SetFOV);
	cameraGui->GetAspectRatio().addListener(this, &Application::SetAspectRatio);
	cameraGui->GetFarClipping().addListener(this, &Application::SetFarClippingPlane);
	cameraGui->GetNearClipping().addListener(this, &Application::SetNearClippingPlane);

	cameraGui->GetObjectCreatorButton().addListener(this, &Application::ShowObjectsCreator);
}
// Fonction de mise à jour de l'application
void Application::update()
{
	// Validation de la position en X de la souris
	ofGetMouseX() > 200 ? eventEnabled = true : eventEnabled = false;

	// On met à jour le rendu et les transformations pour les objets sélectionnés
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
	// Si aucun élément n'est sélectionné, on met à jour le gui
	else
	{
		gui->Update();
	}

	if (!eventEnabled)
	{
		renderer->HideAllCustomCursors();
	}
	// Mise à jour du renderer
	renderer->Update();
}
// Fonction permettant l'affichage de l'application et du rendu
void Application::draw()
{
	// Validation des éléments sélectionnés pour mise à jour de leur rendu
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

// Fonction appelant la méthode CreateBox du renderer
void Application::CreateBox()
{
	renderer->CreateBox();
}

// Fonction appelant la méthode CreateSphere du renderer
void Application::CreateSphere()
{
	renderer->CreateSphere();
}

// Fonction appelant la méthode CreateModel du renderer
void Application::CreateModel()
{
	// On récupère le nom du fichier contenu dans la textbox Filepath
	const std::string& filepath(gui->GetImageInputField().GetValue());
	// Si le fichier existe, on appelle la fonction du renderer pour créer le modèle
	if (ofFile::doesFileExist(filepath))
	{
		renderer->CreateModel(filepath);
	}
	else
	{
		// Show error?
	}
	// Réinitialisation de la textbox
	gui->GetImageInputField().leaveFocus();
	gui->GetImageInputField().ResetValue();
}

// Fonction permettant l'appel de la méthode CreateImage de la classe Renderer
void Application::CreateImage()
{
	// On récupère le nom du fichier contenu dans la textbox Filepath
	const std::string& filepath(gui->GetImageInputField().GetValue());
	// Si le fichier existe, on appelle la fonction du renderer pour créer l'image
	if (!filepath.empty() && ofFile::doesFileExist(filepath))
	{
		renderer->CreateImage(filepath);
	}
	else
	{
		// Show error?
	}
	// Réinitialisation de la textbox
	gui->GetImageInputField().leaveFocus();
	gui->GetImageInputField().ResetValue();
}
// Fonction appelant la méthode CreateLemniscate du renderer
void Application::CreateLemniscate()
{
	renderer->CreateLemniscate();
}
// Fonction appelant la méthode CreateTetrahedron du renderer
void Application::CreateTetrahedron()
{
	renderer->CreateTetrahedron();
}
// Fonction appelant la méthode CreateRectangle du renderer
void Application::CreateRectangle() 
{
	renderer->CreateRectangle();
}
// Fonction appelant la méthode CreateLine du renderer
void Application::CreateLine() 
{
	renderer->CreateLine();
}
// Fonction appelant la méthode CreateCercle du renderer
void Application::CreateCercle() 
{
	renderer->CreateCercle();
}
// Fonction appelant la méthode CreateFV du renderer
void Application::CreateFV()
{
	renderer->CreateFV();
}
// Fonction permettant de mettre la vision de la caméra en projection en perspective
void Application::CamToPerspective(const void* sender, bool& pressed)
{
	// Si cliqué, Perspective est en fonction, sinon c'est le mode projection orthogonale
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
// Fonction permettant de mettre la vision de la caméra en projection orthogonale
void Application::CamToOrtho(const void* sender, bool& pressed)
{
	// Si cliqué, orthogonale, sinon perspective
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
// Fonction appelant la méthode du renderer permettant de modifier l'angle d'ouverture du champ de vision
void Application::SetFOV(const void* sender, float& value)
{
	renderer->SetFOV(value);
}
// Fonction appelant la méthode du renderer permettant de modifier le ratio d'aspect
void Application::SetAspectRatio(const void* sender, float& value)
{
	renderer->SetAspectRatio(value);
}
// Fonction appelant la méthode du renderer permettant de modifier la valeur du plan de clipping arrière
void Application::SetFarClippingPlane(const void* sender, float& value)
{
	renderer->SetFarClippingPlane(value);
}
// Fonction appelant la méthode du renderer permettant de modifier la valeur du plan de clipping avancé
void Application::SetNearClippingPlane(const void* sender, float& value)
{
	renderer->SetNearClippingPlane(value);
}
// Fonction permettant l'affichage des options de la caméra
void Application::ShowCamOptions()
{
	cameraGui->GetFovField().SetValue(renderer->GetFOV());
	cameraGui->GetAspectRatio().SetValue(renderer->GetAspectRatio());
	cameraGui->GetFarClipping().SetValue(renderer->GetFarClippingPlane());
	cameraGui->GetNearClipping().SetValue(renderer->GetNearClippingPlane());

	showObjectCreator = false;
}
// Fonction permettant de présenter le menu gui associé à la création d'objets
void Application::ShowObjectsCreator()
{
	showObjectCreator = true;
}
// Fonction envoyant au renderer l'information des boutons de la souris cliqués
void Application::mousePressed(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MousePressed(x, y, button);
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
// Fonction envoyant au renderer l'information sur les boutons relâchés de la souris
void Application::mouseReleased(int x, int y, int button)
{
	if (eventEnabled)
	{
		renderer->MouseRelease(x, y, button);
	}
}
// Fonction permettant la gestion des touches du clavier enfoncées
void Application::keyPressed(int key)
{
	if (eventEnabled)
	{
		// La touche x permet de sauvegarder l'image de la scène actuelle sur le disque dur
		if (key == 'x')
		{
			time_t timev;
			time(&timev);

			ofImage img;
			img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
			img.save("screenshot_" + boost::lexical_cast<std::string>(timev) + ".png");

			return;
		}
		// Touches permettant la sélection des objets dans la scène de 1 à 7 (indexés de 0 à 6)
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
		// Si au moins 1 élément est sélectionné...
		if (index != -1)
		{		
			// Affichage du gui pour la transformation d'un seul élément
			if (renderer->SelectObject(index) && renderer->ObjectsSelectedCount() == 1)
			{
				transformGui->OnSelected(renderer->GetCurrentSelectedObjects()[0]);
			}
		}
		// On retourne au renderer la touche appuyée pour gestion de contrôles.
		renderer->KeyPressed(key);
	}
}
// Fonction envoyant au renderer l'information concernant les touches clavier relâchées
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
