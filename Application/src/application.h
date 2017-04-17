// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"
#include "Gui/gui.h"
#include "Gui/transformGui.h"
#include "Gui/multiTransformGui.h"
#include "Gui/cameraGui.h"

class Application : public ofBaseApp
{
public:

	static Application& getInstance()
	{
		return *instance;
	}

  Application();
  ~Application();

  void setup();
  
  void update();
  void draw();
  ofMaterial* getMaterial() { return material; }
  void mousePressed(int x, int y, int button);
  void mouseDragged(int x, int y, int button);
  void mouseScrolled(int x, int y, float scrollX, float scrollY);
  void mouseReleased(int x, int y, int button);
  void keyPressed(int key);
  void keyReleased(int key);

  void exit();

  Renderer* getRenderer() { return renderer; }

private:
	static Application* instance;

	void CreateRectangle();
	void CreateLine();
	void CreateCercle();
	void CreateFV();
	void CreateBox();
	void CreateSphere();
	void CreateModel();
	void CreateImage();
	void CreateLemniscate();
	void CreateIcosahedron();
	void CreateCubeMap();
	void CreateQuadratic();
	void CreateCubic();
	void CreateHermite();
	void CreateBSpline();

	void CreateSurface();

	void CreateDirectionalLight();
	void CreateAmbiantLight();
	void CreateSpotLight();
	void CreatePointLight();

	void ShowCamOptions();
	void ShowObjectsCreator();

	void SetMaterial1(const void* sender, bool& pressed);
	void SetMaterial2(const void* sender, bool& pressed);
	void SetMaterial3(const void* sender, bool& pressed);

	void CamToPerspective(const void* sender, bool& pressed);
	void CamToOrtho(const void* sender, bool& pressed);
	void SetFOV(const void* sender, float& value);
	void SetAspectRatio(const void* sender, float& value);
	void SetFarClippingPlane(const void* sender, float& value);
	void SetNearClippingPlane(const void* sender, float& value);
	void SetGridActivated(const void* sender, bool& pressed);

	Renderer* renderer;

	Gui* gui;
	TransformGui* transformGui;
	MultiTransformGui* multiTransformGui;
	CameraGui* cameraGui;

	ofMaterial* material;
	bool eventEnabled;
	bool showObjectCreator;
};
