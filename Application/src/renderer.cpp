// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer()
	: screenPosition(ofVec2f(512.0f, 368.0f))
	, screenScale(ofVec2f(1.0f, 1.0f))
	, screenRotation(ofVec2f(0.0f, 0.0f))
	, previousMousePosition(ofVec2f(0.0f, 0.0f))
	, selectedObject(nullptr)
	, ctrlPressed(false)
{}

Renderer::~Renderer() {}

void Renderer::Setup()
{
	ofSetFrameRate(60);
	// Set background to black
	ofBackground(0, 0, 0);

	objectsList.push_back(new Box(125, 125, 0, 20, 20, 20));
	objectsList.push_back(new Sphere(250, 250, 0, 20));
	objectsList.push_back(new Image(-150, 15, 50, "tableflip.jpg"));
	objectsList.push_back(new LemniscateProceduralImage(-150, -150, 0));

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
	// draw cursor in front of everything, without transform modification
	moveCursor->Draw();
	rotationCursor->Draw();
	scaleCursor->Draw();

	// apply the current screen translation
	ofTranslate(screenPosition);

	// apply the current screen scale
	ofScale(screenScale);

	// apply the current screen rotation
	ofRotateX(screenRotation.x);
	ofRotateY(screenRotation.y);

	ofDrawGrid(50.0f);
	//DrawCursor(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < objectsList.size(); i++)
	{
		objectsList[i]->Draw();
	}
}

void Renderer::DrawCursor(float x, float y, float z) const
{
	float length = 50.0f;

	ofSetLineWidth(5);

	// X arrow
	ofSetColor(255, 0, 0);
	ofDrawLine(x, y, z, x + length, y, z);

	ofSetColor(0, 255, 0);
	ofDrawLine(x, y, z, x, y - length, z);

	ofSetColor(0, 0, 255);
	ofDrawLine(x, y, z, x, y, z + length);
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

		//SetCursorPos(moveCursor->pos.x , moveCursor->pos.y);

		if (selectedObject != nullptr)
		{
			selectedObject->pos.x += x - previousMousePosition.x;
			selectedObject->pos.y += y - previousMousePosition.y;
		}
		else
		{
			screenPosition.x += x - previousMousePosition.x;
			screenPosition.y += y - previousMousePosition.y;
		}

	}
	// right button
	else if (button == 2)
	{
		ofHideCursor();

		rotationCursor->pos.x += x - previousMousePosition.x;
		rotationCursor->pos.y += y - previousMousePosition.y;

		screenRotation.y += x - previousMousePosition.x;
		screenRotation.x += y - previousMousePosition.y;
	}

	previousMousePosition = ofVec2f(x, y);
}

void Renderer::MouseScrolled(int x, int y, float scrollX, float scrollY)
{
	if (ctrlPressed)
	{
		screenScale.x = max(0.1f, screenScale.x + scrollY / 10.0f);
		screenScale.y = max(0.1f, screenScale.y + scrollY / 10.0f);
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

	if (key == '1')
	{
		selectedObject->SetColor(255, 0, 0);
	}
	else if (key == '2')
	{
		selectedObject->SetColor(0, 255, 0);
	}
	else if (key == '3')
	{
		selectedObject->SetAlpha(125);
	}
	else if (key == '4')
	{
		selectedObject->SetAlpha(255);
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


