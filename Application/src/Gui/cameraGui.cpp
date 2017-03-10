#include "cameraGui.h"

CameraGui::CameraGui()
	: BaseGui()
{
	pos = ofVec3f(0.0f, 0.0f);
}

CameraGui::~CameraGui()
{
}

void CameraGui::Setup()
{
	BaseGui::Setup();
	
	gui.setup();
	
	gui.add(perspToggle.setup("Perspective", true));
	gui.add(orthoToggle.setup("Orthographic", false));


	gui.add(showObjectsCreator.setup("Objects Creator"));
}
