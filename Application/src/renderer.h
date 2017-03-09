// IFT3100H17_ClearScreen/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "Objects/baseObject.h"

#include "Objects/Object3d/Box.h"
#include "Objects/Object3d/Sphere.h"

#include "Objects/Object2d/Image.h"
#include "Objects/Object2d/lemniscateProceduralImage.h"

#include "Objects/Object2d/Cursor/cursor.h"

#include "Objects/Object2d/primitive/line.h"
#include "Objects/Object2d/primitive/circle.h"
#include "Objects/Object2d/primitive/rect.h"

class Renderer
{
public:

  Renderer();

  void Setup();

  void Update();
  void Draw();

  void MousePressed(int x, int y, int button);
  void MouseDragged(int x, int y, int button);
  void MouseScrolled(int x, int y, float scrollX, float scrollY);
  void MouseRelease(int x, int y, int button);
  void KeyPressed(int key);
  void keyReleased(int key);

  ~Renderer();

private:
	std::vector<BaseObject*> objectsList;

	BaseObject* selectedObject;

	ofVec2f screenPosition;
	ofVec2f screenScale;
	ofVec2f screenRotation;

	ofVec2f previousMousePosition;

	Cursor* moveCursor;
	Cursor* rotationCursor;
	Cursor* scaleCursor;

	bool ctrlPressed;
	bool leftMousePressed;

	ofEasyCam cam;
};
