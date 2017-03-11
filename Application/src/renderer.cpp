// Classe responsable du rendu de l'application.

#include "renderer.h"
// Constructeur de la classe Renderer avec initialisation des param�tres
Renderer::Renderer()
	: screenPosition(ofVec2f(0.0f, 0.0f))
	, screenScale(1.0f)
	, screenRotation(ofVec2f(0.0f, 0.0f))
	, previousMousePosition(ofVec2f(0.0f, 0.0f))
	, selectedObjects(std::vector<BaseObject*>())
	, undoActions(std::deque<std::vector<UndoAction*> >())
	, leftMousePressed(false)
	, shiftPressed(false)
{

}
// Destructeur de la classe renderer.
Renderer::~Renderer()
{
	// On d�truit la liste des objets cr��s pour la sc�ne
	for (int i = 0, count = objectsList.size(); i < count; i++)
	{
		delete objectsList[i];
		objectsList[i] = nullptr;
	}
	// On d�truit la liste
	objectsList.clear();

	// On vide et r�initialise la liste d'objets s�lectionn�s
	for (int i = 0, count = selectedObjects.size(); i < count; i++)
	{
		delete selectedObjects[i];
		selectedObjects[i] = nullptr;
	}
	// On d�truit la liste d'objets s�lectionn�s
	selectedObjects.clear();

	// On vide le tableau des actions effectu�es
	for (int i = 0; i < MAX_UNDO_ACTIONS; i++)
	{
		for (int j = 0, count = undoActions[i].size(); j < count; j++)
		{
			delete undoActions[i][j]->obj;
			undoActions[i][j]->obj = nullptr;
		}

		undoActions[i].clear();
	}
	// On d�truit le tableau
	undoActions.clear();
}
// Fonction permettant l'initialisation du renderer
void Renderer::Setup()
{
	// D�termination de la distance de la cam�ra pour rendu de sc�ne
	cam.setDistance(1500.0f);
	cam.disableMouseInput();
	// G�n�ration d'une instance de lumi�re pour �clairer la sc�ne
	light = new ofLight();
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	ofSetFrameRate(60);
	// Set background to black
	ofBackground(0, 0, 0);

	/*objectsList.push_back(new Box(125, 125, 0, 20, 20, 20));
	objectsList.push_back(new Sphere(250, 250, 0, 20));
	objectsList.push_back(new Image(-150, 15, 50, "tableflip.jpg"));
	objectsList.push_back(new LemniscateProceduralImage(-150, -150, 0));

	objectsList.push_back(new Line(ofPoint(0, 0, 0), ofPoint(100, 100, 100), 5.0f, ofColor::yellow));
	objectsList.push_back(new Circle(ofPoint(-150, -150, 0), 50.0f, 3.0f, false, ofColor::blue));
	objectsList.push_back(new Rect(ofPoint(250, -250, 0), 45.0f, 45.0f, 3.0f, false, ofColor::pink));*/
	// Mise � jour des objets contenus dans la liste
	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Setup();
	}
	// Cr�ation des curseurs qui seront utilis�s pour les diff�rentes transformations dans l'espace
	moveCursor = new Cursor("cursors/move.png");
	rotationCursor = new Cursor("cursors/rotation.png");
	scaleCursor = new Cursor("cursors/zoom.png");

	camParent.setPosition(ofVec3f::zero());
	cam.setParent(camParent);
	cam.setPosition(ofVec3f(0.0f, 0.0f, cam.getDistance()));

	// TEMP: For testing.
	//m_SelectedObject = m_ObjectsList[3];
}
// Fonction permettant la mise � jour des objets de la sc�ne
void Renderer::Update()
{
	// Mise � jour de tous les objets de la sc�ne
	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Update();
	}
}
// Fonction permettant le rendu du renderer
void Renderer::Draw()
{
	// Configuration de param�tres de la lumi�re pour l'affichage
	ofEnableDepthTest();
	ofEnableLighting();
	light->setAmbientColor(ofColor(255, 255, 255));
	light->setDiffuseColor(ofColor(255, 255, 255));
	light->enable();
	light->setPosition(0, 150, 0);
	// Activation de la cam�ra
	cam.begin();
	cam.setDistance(1500.0f * screenScale);
	cam.setPosition(ofVec3f(-screenPosition.x, -screenPosition.y, cam.getDistance()));
	camParent.setOrientation(screenRotation);

	// Affichage d'une bo�te autour des objects s�lectionn�s
	for (int i = 0; i < selectedObjects.size(); i++)
	{
		selectedObjects[i]->DrawBoundingBox();
	}
	// Affichage de tous les objets de la sc�ne
	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Draw();
	}
	// Affichage d'une grille pour positionner les objets
	ofDrawGrid(100.0f);
	cam.end();
	ofDisableDepthTest();

	moveCursor->Draw();
	rotationCursor->Draw();
	scaleCursor->Draw();
}
// Fonction permettant de g�n�rer un rectangle
void Renderer::CreateRectangle()
{
	ofPoint pt; pt.x = 0; pt.y = 0;
	objectsList.push_back(new Rect(pt,150,100,3,1,ofColor(255,0,0)));
}
// Fonction permettant de g�n�rer une ligne
void Renderer::CreateLine()
{
	objectsList.push_back(new Line(ofPoint(0, 0, 0), ofPoint(100, 100, 100), 5.0f, ofColor::white));
}
// Fonction permettant de g�n�rer un cercle
void Renderer::CreateCercle()
{
	objectsList.push_back(new Circle(ofPoint(0, 0, 0), 50.0f, 3.0f, false, ofColor::white));
}
// Fonction permettant de g�n�rer une Forme vectorielle
void Renderer::CreateFV()
{
	ofDrawCircle(150, 150, 100);//objectsList.push_back(new Primitive());
	ofSetColor(0, 0, 255);
	ofFill();
	for (int i = 0; i < 12; i++) { ofDrawTriangle(ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100)); }
}
// Fonction permettant de g�n�rer un cube
void Renderer::CreateBox()
{
	objectsList.push_back(new Box());
}
// Fonction permettant de g�n�rer une sph�re
void Renderer::CreateSphere()
{
	objectsList.push_back(new Sphere());
}
// Fonction permettant de g�n�rer un t�trah�dre
void Renderer::CreateIcosahedron()
{
	objectsList.push_back(new Icosahedron());
}
// Fonction permettant la g�n�ration d'une image � l'aide d'un chemin source
void Renderer::CreateImage(const std::string& filepath)
{
	objectsList.push_back(new Image(filepath));
}
// Fonction permettant la g�n�ration d'un mod�le � l'aide d'un chemin source
void Renderer::CreateModel(const std::string& filepath)
{
	objectsList.push_back(new ModelObj(filepath));
}
// Fonction permettant la g�n�ration d'une image proc�durale : Le Lemniscate
void Renderer::CreateLemniscate()
{
	objectsList.push_back(new LemniscateProceduralImage());
}
// Fonctions activ�es lorsqu'une touche de la souris est activ�e
void Renderer::MousePressed(int x, int y, int button)
{
	if (selectedObjects.size() > 0)
	{
		// Effacer la premi�re action
		if (undoActions.size() == MAX_UNDO_ACTIONS)
		{
			undoActions.pop_front();
		}

		// Ajouter une action pour chaque objet s�lectionn�
		std::vector<UndoAction*> actions;
		for (int i = 0, count = selectedObjects.size(); i < count; i++)
		{
			actions.push_back(new UndoAction(selectedObjects[i]));
		}
		undoActions.push_back(actions);
	}

	ofHideCursor();
	// Si le bouton de gauche est enfonc�
	if (button == 0)
	{
		bool hit = false;
		for (int i = 0, count = objectsList.size(); i < count; i++)
		{
			ofVec3f sPos = cam.worldToScreen(objectsList[i]->pos);
			hit = objectsList[i]->CheckPointCollision(ofVec3f(ofGetMouseX(), ofGetMouseY(), 0.0f), sPos);
			if (hit)
			{
				std::vector<BaseObject*>::iterator obj = std::find(selectedObjects.begin(), selectedObjects.end(), objectsList[i]);
				if (obj == selectedObjects.end())
				{
					selectedObjects.push_back(objectsList[i]);
				}
				break;
			}
		}
		
		if (!hit)
		{
			selectedObjects.clear();
		}

		moveCursor->pos = ofVec2f(x, y);
		moveCursor->Show();
	}
	// Si le bouton de droite est enfonc�
	else if (button == 2)
	{
		// Rotation
		rotationCursor->pos = ofVec2f(x, y);
		rotationCursor->Show();
	}
	// Position pr�c�dente
	previousMousePosition = ofVec2f(x, y);
}
// Fonctions activ�es lorsque la souris est d�plac�e alors qu'un bouton est enfonc�
void Renderer::MouseDragged(int x, int y, int button)
{
	// Le bouton de gauche pour les translations
	if (button == 0)
	{
		ofHideCursor();

		moveCursor->pos.x += x - previousMousePosition.x;
		moveCursor->pos.y += y - previousMousePosition.y;
		// On d�place par translation tous les �l�ments s�lectionn�s
		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->pos.x += x - previousMousePosition.x;
				selectedObjects[i]->pos.y -= y - previousMousePosition.y;
			}
		}
		// Sinon on d�place l'espace
		else
		{
			screenPosition.x += x - previousMousePosition.x;
			screenPosition.y -= y - previousMousePosition.y;
		}

	}
	// Le bouton de droite pour les rotations
	else if (button == 2)
	{
		ofHideCursor();
		// On r�cup�re le d�placement effectu� par la souris
		rotationCursor->pos.x += x - previousMousePosition.x;
		rotationCursor->pos.y += y - previousMousePosition.y;
		// On applique le d�placement � tous les objets s�lectionn�s
		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->rot.y += x - previousMousePosition.x;
				selectedObjects[i]->rot.x -= y - previousMousePosition.y;
			}
		}
		// Sinon on applique la position � l'espace
		else
		{
			screenRotation.y += x - previousMousePosition.x;
			screenRotation.x += y - previousMousePosition.y;

			ClampRotation();
		}
	}

	previousMousePosition = ofVec2f(x, y);

}
// Fonctions activ�es lorsque la molette centrale de la souris est tourn�e
void Renderer::MouseScrolled(int x, int y, float scrollX, float scrollY)
{
	// Si la touche shift est enfonc�e, le zoom est permis.
	if (shiftPressed)
	{
		// On applique un rapport d'homoth�tie sur tous les objets s�lectionn�s
		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->scale.x = max(0.1f, selectedObjects[i]->scale.x + scrollY / 10.0f);
				selectedObjects[i]->scale.y = max(0.1f, selectedObjects[i]->scale.y + scrollY / 10.0f);
				selectedObjects[i]->scale.z = max(0.1f, selectedObjects[i]->scale.z + scrollY / 10.0f);
			}
		}
		// On applique un rapport d'homoth�tie sur l'espace
		else
		{
			screenScale = max(0.1f, screenScale - scrollY / 10.0f);
		}
	}

}
// Fonctions activ�es lorsqu'on rel�che un bouton de la souris
void Renderer::MouseRelease(int x, int y, int button)
{
	// On cache le curseur de translation
	if (button == 0)
	{
		moveCursor->Hide();
	}
	// On cache le curseur de rotation
	else if (button == 2)
	{
		rotationCursor->Hide();
	}
	// On affiche le curseur standard
	ofShowCursor();

}
// Fonctions activ�es lorsqu'une touche clavier est enfonc�e
void Renderer::KeyPressed(int key)
{
	// Si shift est enfonc�, on permet le zoom
	if (key == OF_KEY_SHIFT)
	{
		ofHideCursor();

		scaleCursor->pos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		// On affiche le curseur de redimensionnement
		scaleCursor->Show();

		shiftPressed = true;
	}
	// Switch sur les touches enfonc�es
	switch (key)
	{
		// Appuyer sur u permet de vider la liste de s�lection d'objets
	case 'u':
		selectedObjects.clear();
		break;
	default:
		break;
	}
}
// Fonctions appel�es lorsqu'une touche clavier est rel�ch�e
void Renderer::keyReleased(int key)
{
	// Si on rel�che la touche Shift, le zoom n'est plus possible
	if (key == OF_KEY_SHIFT)
	{
		shiftPressed = false;

		scaleCursor->Hide();
		ofShowCursor();
	}
	// Si on rel�che ctrl + z
	else if (key == 26)
	{
		// Si la liste d'actions � supprimer n'est pas vide, on annule la derni�re action
		if (!undoActions.empty())
		{
			std::vector<UndoAction*> toApply = undoActions[undoActions.size() - 1];
			undoActions.pop_back();

			for (int i = 0, count = toApply.size(); i < count; i++)
			{
				toApply[i]->obj->pos = toApply[i]->pos;
				toApply[i]->obj->rot = toApply[i]->rot;
				toApply[i]->obj->scale = toApply[i]->scale;
			}
		}
	}
}
// Fonction permettant de cacher les curseurs sp�ciaux
void Renderer::HideAllCustomCursors()
{
	ofShowCursor();

	moveCursor->Hide();
	rotationCursor->Hide();
	scaleCursor->Hide();
}
// Fonction permettant de choisir des objets d'une sc�ne
bool Renderer::SelectObject(int index)
{

	if (index != -1)
	{
		std::vector<BaseObject*>::iterator obj = std::find(selectedObjects.begin(), selectedObjects.end(), objectsList[index]);
		// Si l'objet est d�j� dans la liste, on l'enl�ve
		if (obj != selectedObjects.end())
		{
			selectedObjects.erase(obj);
		}
		// Sinon, on l'ajoute � la fin du vecteur
		else
		{
			selectedObjects.push_back(objectsList[index]);
			return true;
		}
	}

	return false;
}

void Renderer::ClampRotation()
{
	if (screenRotation.x > 359.0f)
		screenRotation.x = screenRotation.x - 360.0f;
	else if (screenRotation.x < 0.0f)
		screenRotation.x = 359.0f;

	if (screenRotation.y > 359.0f)
		screenRotation.y = screenRotation.y - 360.0f;
	else if (screenRotation.y < 0.0f)
		screenRotation.y = 359.0f;
}