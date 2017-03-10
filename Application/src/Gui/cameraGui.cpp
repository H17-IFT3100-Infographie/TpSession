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

	gui.add(fovField.setup("FOV", 60, 0, 300));
	gui.add(aspectRatio.setup("Aspect Ratio", 1.33f, 0, 2.0f));
	gui.add(farClipping.setup("Far", 2000, 0, 3000));
	gui.add(nearClipping.setup("Near", 0, 0, 3000));

	gui.add(showObjectsCreator.setup("Objects Creator"));
}
