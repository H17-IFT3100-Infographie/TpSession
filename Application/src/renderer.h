// IFT3100H17_ClearScreen/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "Objects/baseObject.h"
#include "Objects/Cube.h"

class Renderer
{
public:

  Renderer();

  void setup();
  void draw();

  void LeftArrowPressed();
  void RightArrowPressed();

  ~Renderer();

private:

	void AddCube(int x, int y, int z, int width, int height, int depth);


	std::vector<BaseObject*> m_ObjectsList;
};
