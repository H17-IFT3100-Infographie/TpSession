// IFT3100H17_ClearScreen/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "Gui/gui.h"
#include "Gui/transformGui.h"
#include "Gui/multiTransformGui.h"

class Application : public ofBaseApp
{
public:

  Renderer* renderer;

  Gui* gui;
  TransformGui* transformGui;
  MultiTransformGui* multiTransformGui;

  Application();
  ~Application();

  void setup();
  
  void update();
  void draw();

  void mousePressed(int x, int y, int button);
  void mouseDragged(int x, int y, int button);
  void mouseScrolled(int x, int y, float scrollX, float scrollY);
  void mouseReleased(int x, int y, int button);
  void keyPressed(int key);
  void keyReleased(int key);

  void exit();

private:
	void CreateBox();
	void CreateSphere();
	void CreateModel();
	void CreateImage();
	void CreateLemniscate();

	bool eventEnabled;
};
