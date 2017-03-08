// IFT3100H17_ClearScreen/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "Objects/baseObject.h"
#include "Objects/Box.h"
#include "Objects/Sphere.h"
#include "Objects/Image.h"

class Renderer
{
public:

  Renderer();

  void Setup();
  void Draw();

  void MousePressed(int x, int y, int button);
  void MouseDragged(int x, int y, int button);
  void MouseScrolled(int x, int y, float scrollX, float scrollY);

  ~Renderer();

private:
	void DrawCursor(float x, float y, float z) const;

	std::vector<BaseObject*> m_ObjectsList;

	BaseObject* m_SelectedObject;

	ofVec2f screenPosition;
	ofVec2f screenScale;
	ofVec2f screenRotation;

	ofVec2f previousMousePosition;
};
