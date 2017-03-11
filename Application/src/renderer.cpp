// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

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

Renderer::~Renderer()
{
	for (int i = 0, count = objectsList.size(); i < count; i++)
	{
		delete objectsList[i];
		objectsList[i] = nullptr;
	}
	objectsList.clear();

	for (int i = 0, count = selectedObjects.size(); i < count; i++)
	{
		delete selectedObjects[i];
		selectedObjects[i] = nullptr;
	}
	selectedObjects.clear();

	for (int i = 0; i < MAX_UNDO_ACTIONS; i++)
	{
		for (int j = 0, count = undoActions[i].size(); j < count; j++)
		{
			delete undoActions[i][j]->obj;
			undoActions[i][j]->obj = nullptr;
		}

		undoActions[i].clear();
	}
	undoActions.clear();
}

void Renderer::Setup()
{
	cam.setDistance(1500.0f);
	cam.disableMouseInput();
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

	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Setup();
	}

	moveCursor = new Cursor("cursors/move.png");
	rotationCursor = new Cursor("cursors/rotation.png");
	scaleCursor = new Cursor("cursors/zoom.png");

	camParent.setPosition(ofVec3f::zero());
	cam.setParent(camParent);
	cam.setPosition(ofVec3f(0.0f, 0.0f, cam.getDistance()));

	// TEMP: For testing.
	//m_SelectedObject = m_ObjectsList[3];
}

void Renderer::Update()
{
	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Update();
	}
}

void Renderer::Draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	light->setAmbientColor(ofColor(255, 255, 255));
	light->setDiffuseColor(ofColor(255, 255, 255));
	light->enable();
	light->setPosition(0, 150, 0);
	cam.begin();
	cam.setDistance(1500.0f * screenScale);
	cam.setPosition(ofVec3f(-screenPosition.x, -screenPosition.y, cam.getDistance()));
	camParent.setOrientation(screenRotation);

	for (int i = 0; i < selectedObjects.size(); i++)
	{
		selectedObjects[i]->DrawBoundingBox();
	}

	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Draw();
	}

	ofDrawGrid(100.0f);
	cam.end();
	ofDisableDepthTest();

	moveCursor->Draw();
	rotationCursor->Draw();
	scaleCursor->Draw();
}
void Renderer::CreateRectangle()
{
	ofPoint pt; pt.x = 0; pt.y = 0;
	objectsList.push_back(new Rect(pt,150,100,3,1,ofColor(255,0,0)));
}
void Renderer::CreateLine()
{
	objectsList.push_back(new Line(ofPoint(0, 0, 0), ofPoint(100, 100, 100), 5.0f, ofColor::white));
}
void Renderer::CreateCercle()
{
	objectsList.push_back(new Circle(ofPoint(0, 0, 0), 50.0f, 3.0f, false, ofColor::white));
}
void Renderer::CreateFV()
{
	ofDrawCircle(150, 150, 100);//objectsList.push_back(new Primitive());
	ofSetColor(0, 0, 255);
	ofFill();
	for (int i = 0; i < 12; i++) { ofDrawTriangle(ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100), ofRandom(0, 100)); }
}
void Renderer::CreateBox()
{
	objectsList.push_back(new Box());
}

void Renderer::CreateSphere()
{
	objectsList.push_back(new Sphere());
}

void Renderer::CreateTetrahedron()
{
	objectsList.push_back(new Tetrahedron());
}

void Renderer::CreateImage(const std::string& filepath)
{
	objectsList.push_back(new Image(filepath));
}

void Renderer::CreateModel(const std::string& filepath)
{
	objectsList.push_back(new ModelObj(filepath));
}

void Renderer::CreateLemniscate()
{
	objectsList.push_back(new LemniscateProceduralImage());
}

void Renderer::MousePressed(int x, int y, int button)
{
	if (selectedObjects.size() > 0)
	{
		// remove the first in.
		if (undoActions.size() == MAX_UNDO_ACTIONS)
		{
			undoActions.pop_front();
		}

		// add actions for each objects selected
		std::vector<UndoAction*> actions;
		for (int i = 0, count = selectedObjects.size(); i < count; i++)
		{
			actions.push_back(new UndoAction(selectedObjects[i]));
		}
		undoActions.push_back(actions);
	}

	ofHideCursor();
	// left mouse button pressed
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
	// right mouse button pressed
	else if (button == 2)
	{
		rotationCursor->pos = ofVec2f(x, y);
		rotationCursor->Show();
	}
	previousMousePosition = ofVec2f(x, y);
}

void Renderer::MouseDragged(int x, int y, int button)
{
	// left button
	if (button == 0)
	{
		ofHideCursor();

		moveCursor->pos.x += x - previousMousePosition.x;
		moveCursor->pos.y += y - previousMousePosition.y;

		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->pos.x += x - previousMousePosition.x;
				selectedObjects[i]->pos.y -= y - previousMousePosition.y;
			}
		}
		else
		{
			screenPosition.x += x - previousMousePosition.x;
			screenPosition.y -= y - previousMousePosition.y;
		}

	}
	// right button
	else if (button == 2)
	{
		ofHideCursor();

		rotationCursor->pos.x += x - previousMousePosition.x;
		rotationCursor->pos.y += y - previousMousePosition.y;

		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->rot.y += x - previousMousePosition.x;
				selectedObjects[i]->rot.x -= y - previousMousePosition.y;
			}
		}
		else
		{
			screenRotation.y += x - previousMousePosition.x;
			screenRotation.x += y - previousMousePosition.y;

			ClampRotation();
		}
	}

	previousMousePosition = ofVec2f(x, y);

}

void Renderer::MouseScrolled(int x, int y, float scrollX, float scrollY)
{
	if (shiftPressed)
	{
		if (selectedObjects.size() > 0)
		{
			for (int i = 0, count = selectedObjects.size(); i < count; i++)
			{
				selectedObjects[i]->scale.x = max(0.1f, selectedObjects[i]->scale.x + scrollY / 10.0f);
				selectedObjects[i]->scale.y = max(0.1f, selectedObjects[i]->scale.y + scrollY / 10.0f);
				selectedObjects[i]->scale.z = max(0.1f, selectedObjects[i]->scale.z + scrollY / 10.0f);
			}
		}
		else
		{
			screenScale = max(0.1f, screenScale - scrollY / 10.0f);
		}
	}

}

void Renderer::MouseRelease(int x, int y, int button)
{
	if (button == 0)
	{
		moveCursor->Hide();
	}
	else if (button == 2)
	{
		rotationCursor->Hide();
	}

	ofShowCursor();

}

void Renderer::KeyPressed(int key)
{
	if (key == OF_KEY_SHIFT)
	{
		ofHideCursor();

		scaleCursor->pos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		scaleCursor->Show();

		shiftPressed = true;
	}

	switch (key)
	{
	case 'u':
		selectedObjects.clear();
		break;
	default:
		break;
	}
}

void Renderer::keyReleased(int key)
{
	if (key == OF_KEY_SHIFT)
	{
		shiftPressed = false;

		scaleCursor->Hide();
		ofShowCursor();
	}
	else if (key == 26)
	{
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

void Renderer::HideAllCustomCursors()
{
	ofShowCursor();

	moveCursor->Hide();
	rotationCursor->Hide();
	scaleCursor->Hide();
}

bool Renderer::SelectObject(int index)
{
	if (index != -1)
	{
		std::vector<BaseObject*>::iterator obj = std::find(selectedObjects.begin(), selectedObjects.end(), objectsList[index]);
		if (obj != selectedObjects.end())
		{
			selectedObjects.erase(obj);
		}
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