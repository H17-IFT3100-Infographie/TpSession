// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer()
	: screenPosition(ofVec2f(0.0f, 0.0f))
	, screenScale(ofVec2f(1.0f, 1.0f))
	, screenRotation(ofVec2f(0.0f, 0.0f))
	, previousMousePosition(ofVec2f(0.0f, 0.0f))
	, selectedObject(nullptr)
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

		if (selectedObject != nullptr)
		{
			selectedObject->pos.x += x - previousMousePosition.x;
			selectedObject->pos.y -= y - previousMousePosition.y;
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

		if (selectedObject != nullptr)
		{
			selectedObject->rot.y += x - previousMousePosition.x;
			selectedObject->rot.x -= y - previousMousePosition.y;
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
		if (selectedObject != nullptr)
		{
			selectedObject->scale.x = max(0.1f, selectedObject->scale.x + scrollY / 10.0f);
			selectedObject->scale.y = max(0.1f, selectedObject->scale.y + scrollY / 10.0f);
			selectedObject->scale.z = max(0.1f, selectedObject->scale.z + scrollY / 10.0f);
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

	if (selectedObject != nullptr) selectedObject->SetColor(ofColor::white);

	if (key == 'u') selectedObject = nullptr;
	else if (key == '1') selectedObject = objectsList[0];
	else if (key == '2') selectedObject = objectsList[1];
	else if (key == '3') selectedObject = objectsList[2];
	else if (key == '4') selectedObject = objectsList[3];
	else if (key == '5') selectedObject = objectsList[4];
	else if (key == '6') selectedObject = objectsList[5];
	else if (key == '7') selectedObject = objectsList[6];

	if (selectedObject != nullptr) selectedObject->SetColor(ofColor::yellow);
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


