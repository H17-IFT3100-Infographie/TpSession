// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer()
	: screenPosition(ofVec2f(512.0f, 368.0f))
	, screenScale(ofVec2f(1.0f, 1.0f))
	, previousMousePosition(ofVec2f(0.0f, 0.0f))
{}

Renderer::~Renderer() {}

void Renderer::Setup()
{
	ofSetFrameRate(60);
	// Set background to black
	ofBackground(0, 0, 0);

	m_ObjectsList.push_back(new Box(125, 125, 0, 20, 20, 20));
	m_ObjectsList.push_back(new Sphere(250, 250, 0, 20));
}

void Renderer::Draw()
{
	ofTranslate(screenPosition);
	ofScale(screenScale);
	ofDrawGrid(50.0f);

	for (int i = 0; i < m_ObjectsList.size(); i++)
	{
		m_ObjectsList[i]->Draw();
	}
}

void Renderer::MousePressed(int x, int y, int button)
{
	previousMousePosition = ofVec2f(x, y);
}

void Renderer::MouseDragged(int x, int y, int button)
{
	screenPosition.x += x - previousMousePosition.x;
	screenPosition.y += y - previousMousePosition.y;

	previousMousePosition = ofVec2f(x, y);
}

void Renderer::MouseScrolled(int x, int y, float scrollX, float scrollY)
{
	screenScale.x = max(0.1f, screenScale.x + scrollY / 10.0f);
	screenScale.y = max(0.1f, screenScale.y + scrollY / 10.0f);
}

void Renderer::LeftArrowPressed()
{
	m_ObjectsList[0]->Translate(ofVec3f(-1.0f, 0.0f, 0.0f));
}

void Renderer::RightArrowPressed()
{
	m_ObjectsList[0]->Translate(ofVec3f(1.0f, 0.0f, 0.0f));
}


