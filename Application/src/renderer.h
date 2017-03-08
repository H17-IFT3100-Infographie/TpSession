// IFT3100H17_ClearScreen/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "Objects/baseObject.h"
#include "Objects/Cube.h"
#include "Objects/Sphere.h"

class Renderer
{
public:

  Renderer();

  void Setup();
  void Draw();

  void MousePressed(int x, int y, int button);
  void MouseDragged(int x, int y, int button);
  void MouseScrolled(int x, int y, float scrollX, float scrollY);

  void LeftArrowPressed();
  void RightArrowPressed();

  ~Renderer();

private:
	std::vector<BaseObject*> m_ObjectsList;

	ofVec2f screenPosition;
	ofVec2f screenScale;

	ofVec2f previousMousePosition;
};
