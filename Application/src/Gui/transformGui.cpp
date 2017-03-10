#include "transformGui.h"

TransformGui::TransformGui()
	: BaseGui()
{
}

TransformGui::~TransformGui()
{
}

void TransformGui::Setup()
{
	BaseGui::Setup();

	gui.setup(); // most of the time you don't need a name
	gui.add(posXField.setup("PosX:", 0));
	gui.add(posYField.setup("PosY:", 0));
	gui.add(posZField.setup("PosZ:", 0));
}

void TransformGui::Update(BaseObject* currentObjectSelected)
{
	if (currentObjectSelected != nullptr)
	{
		if (posXField.IsDirty())
			currentObjectSelected->pos.x = posXField.GetValue();

		if (posYField.IsDirty())
			currentObjectSelected->pos.y = posYField.GetValue();

		if (posZField.IsDirty())
			currentObjectSelected->pos.z = posZField.GetValue();

		ofVec3f pos = currentObjectSelected->pos;

		if (!posXField.IsFocus())
			posXField.SetValue(pos.x);

		if (!posYField.IsFocus())
			posYField.SetValue(pos.y);

		if (!posZField.IsFocus())
			posZField.SetValue(pos.z);
	}
	else
	{
		posXField.SetValue(-1);
		posYField.SetValue(-1);
		posZField.SetValue(-1);
	}
}

bool TransformGui::IsAnyGuiFocused()
{
	return posXField.IsFocus() || posYField.IsFocus() || posZField.IsFocus();
}