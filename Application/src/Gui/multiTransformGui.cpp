#include "multiTransformGui.h"

#include <limits>

MultiTransformGui::MultiTransformGui()
	: BaseGui()
	, pos(ofVec3f(0.0f, 0.0f, 0.0f))
	, rot(ofVec3f(0.0f, 0.0f, 0.0f))
	, scale(ofVec3f(0.0f, 0.0f, 0.0f))
{
}

MultiTransformGui::~MultiTransformGui()
{
}

void MultiTransformGui::Setup()
{
	BaseGui::Setup();

	gui.setup(); // most of the time you don't need a name

	gui.add(posXField.setup("PosX:", 0, -1000, 1000));
	gui.add(posYField.setup("PosY:", 0, -1000, 1000));
	gui.add(posZField.setup("PosZ:", 0, -1000, 1000));

	gui.add(rotXField.setup("RotX:", 0, 0, 359));
	gui.add(rotYField.setup("RotY:", 0, 0, 359));
	gui.add(rotZField.setup("RotZ:", 0, 0, 359));

	gui.add(scaleXField.setup("ScaleX:", 1.0f, 0, 200));
	gui.add(scaleYField.setup("ScaleY:", 1.0f, 0, 200));
	gui.add(scaleZField.setup("ScaleZ:", 1.0f, 0, 200));
}

void MultiTransformGui::Update(std::vector<BaseObject*>& currentObjectSelected)
{
	UpdatePosition(currentObjectSelected);
	UpdateRotation(currentObjectSelected);
	UpdateScale(currentObjectSelected);
}

void MultiTransformGui::UpdatePosition(std::vector<BaseObject*>& currentObjectSelected)
{
	if (posXField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->pos.x = posXField.GetValue();
		}
	}

	if (posYField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->pos.y = posYField.GetValue();
		}
	}

	if (posZField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->pos.z = posZField.GetValue();
		}
	}
}

void MultiTransformGui::UpdateRotation(std::vector<BaseObject*>& currentObjectSelected)
{
	if (rotXField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->rot.x = rotXField.GetValue();
		}
	}

	if (rotYField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->rot.y = rotYField.GetValue();
		}
	}

	if (rotZField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->rot.z = rotZField.GetValue();
		}
	}

}

void MultiTransformGui::UpdateScale(std::vector<BaseObject*>& currentObjectSelected)
{
	if (scaleXField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->scale.x = scaleXField.GetValue();
		}
	}

	if (scaleYField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->scale.y = scaleYField.GetValue();
		}
	}

	if (scaleZField.IsDirty())
	{
		for (int i = 0; i < currentObjectSelected.size(); i++)
		{
			currentObjectSelected[i]->scale.z = scaleZField.GetValue();
		}
	}
}

bool MultiTransformGui::IsAnyGuiFocused()
{
	return posXField.IsFocus() ||
		posYField.IsFocus() ||
		posZField.IsFocus() ||
		rotXField.IsFocus() ||
		rotYField.IsFocus() ||
		rotZField.IsFocus() ||
		scaleXField.IsFocus() ||
		scaleYField.IsFocus() ||
		scaleZField.IsFocus();
}