// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer()
	: screenPosition(ofVec2f(0.0f, 0.0f))
	, screenScale(ofVec2f(1.0f, 1.0f))
	, screenRotation(ofVec2f(0.0f, 0.0f))
	, previousMousePosition(ofVec2f(0.0f, 0.0f))
	, selectedObjects(std::vector<BaseObject*>())
	, leftMousePressed(false)
	, ctrlPressed(false)
{}

Renderer::~Renderer() {}

void Renderer::Setup()
{
	cam.setDistance(1000.0f);
	cam.disableMouseInput();
	ofEnableDepthTest();

	ofSetFrameRate(60);
	// Set background to black
	ofBackground(0, 0, 0);

	objectsList.push_back(new Box(125, 125, 0, 20, 20, 20));
	objectsList.push_back(new Sphere(250, 250, 0, 20));
	objectsList.push_back(new Image(-150, 15, 50, "tableflip.jpg"));
	objectsList.push_back(new LemniscateProceduralImage(-150, -150, 0));

	objectsList.push_back(new Line(ofPoint(0, 0, 0), ofPoint(100, 100, 100), 5.0f, ofColor::yellow));
	objectsList.push_back(new Circle(ofPoint(-150, -150, 0), 50.0f, 3.0f, false, ofColor::blue));
	objectsList.push_back(new Rect(ofPoint(250, -250, 0), 45.0f, 45.0f, 3.0f, false, ofColor::pink));

	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Setup();
	}

	moveCursor = new Cursor("cursors/move.png");
	rotationCursor = new Cursor("cursors/rotation.png");
	scaleCursor = new Cursor("cursors/zoom.png");

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
	cam.begin();
	ofTranslate(screenPosition);
	ofScale(screenScale);
	ofRotateX(screenRotation.x);
	ofRotateY(screenRotation.y);

	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Draw();
	}

	ofDrawGrid(50.0f);
	cam.end();

	moveCursor->Draw();
	rotationCursor->Draw();
	scaleCursor->Draw();
}

void Renderer::MousePressed(int x, int y, int button)
{
	ofHideCursor();
	if (button == 0)
	{
		moveCursor->pos = ofVec2f(x, y);
		moveCursor->Show();
	}
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
		}
	}

	previousMousePosition = ofVec2f(x, y);
}

void Renderer::MouseScrolled(int x, int y, float scrollX, float scrollY)
{
	if (ctrlPressed)
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
			screenScale.x = max(0.1f, screenScale.x + scrollY / 10.0f);
			screenScale.y = max(0.1f, screenScale.y + scrollY / 10.0f);
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
	if (key == OF_KEY_CONTROL)
	{
		ofHideCursor();

		scaleCursor->pos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		scaleCursor->Show();

		ctrlPressed = true;
	}

	if (selectedObjects.size() > 0)
	{
		for (int i = 0, count = selectedObjects.size(); i < count; i++)
		{
			selectedObjects[i]->SetColor(ofColor::white);
		}
	}

	int index = -1;
	switch (key)
	{
	case 'u':
		selectedObjects.clear();
		break;
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
		std::vector<BaseObject*>::iterator obj = std::find(selectedObjects.begin(), selectedObjects.end(), objectsList[index]);
		obj != selectedObjects.end() ? selectedObjects.erase(obj) : selectedObjects.push_back(objectsList[index]);
	}

	if (selectedObjects.size() > 0)
	{
		for (int i = 0, count = selectedObjects.size(); i < count; i++)
		{
			selectedObjects[i]->SetColor(ofColor::yellow);
		}
	}
}

void Renderer::keyReleased(int key)
{
	if (key == OF_KEY_CONTROL)
	{
		ctrlPressed = false;

		scaleCursor->Hide();
		ofShowCursor();
	}
}


