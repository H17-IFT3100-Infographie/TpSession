#include "cameraGui.h"

CameraGui::CameraGui()
	: BaseGui()
{
}

CameraGui::~CameraGui()
{
}

void CameraGui::Setup()
{
	BaseGui::Setup();

	gui.setup();
}
