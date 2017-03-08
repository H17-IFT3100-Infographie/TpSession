// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer()
{}

Renderer::~Renderer() {}

void Renderer::setup()
{
	ofSetFrameRate(60);

	// Set background to black
	ofBackground(0, 0, 0);

	AddCube(225, 225, 225, 50, 50, 50);
}

void Renderer::draw()
{
	for (int i = 0; i < m_ObjectsList.size(); i++)
	{
		m_ObjectsList[i]->Draw();
	}
}

void Renderer::AddCube(int x, int y, int z, int width, int height, int depth) 
{
	Box* box = new Box(x, y, z, width, height, depth);
	m_ObjectsList.push_back(box);
}

void Renderer::LeftArrowPressed()
{
	m_ObjectsList[0]->Translate(ofVec3f(-1.0f, 0.0f, 0.0f));
}

void Renderer::RightArrowPressed()
{
	m_ObjectsList[0]->Translate(ofVec3f(1.0f, 0.0f, 0.0f));
}


