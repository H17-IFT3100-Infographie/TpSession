#include "transformGui.h"

#include <limits>

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

	gui.add(posXField.setup("PosX:", 0, -1000, 1000));
	gui.add(posYField.setup("PosY:", 0, -1000, 1000));
	gui.add(posZField.setup("PosZ:", 0, -1000, 1000));

	gui.add(rotXField.setup("RotX:", 0, 0, 359));
	gui.add(rotYField.setup("RotY:", 0, 0, 359));
	gui.add(rotZField.setup("RotZ:", 0, 0, 359));

	gui.add(scaleXField.setup("ScaleX:", 1.0f, 0, 200));
	gui.add(scaleYField.setup("ScaleY:", 1.0f, 0, 200));
	gui.add(scaleZField.setup("ScaleZ:", 1.0f, 0, 200));

	gui.add(colorSlider.setup("Color", ofColor::white, ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
}

void TransformGui::OnSelected(BaseObject* currentObjectSelected)
{
	colorSlider = currentObjectSelected->GetColor();
}

void TransformGui::Update(BaseObject* currentObjectSelected)
{
	if (currentObjectSelected != nullptr)
	{
		UpdatePosition(currentObjectSelected);
		UpdateRotation(currentObjectSelected);
		UpdateScale(currentObjectSelected);
		UpdateColor(currentObjectSelected);
		UpdateAlpha(currentObjectSelected);
	}
	else
	{
		posXField.SetValue(-1);
		posYField.SetValue(-1);
		posZField.SetValue(-1);
	}
}

void TransformGui::UpdatePosition(BaseObject* currentObjectSelected)
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

void TransformGui::UpdateRotation(BaseObject* currentObjectSelected)
{
	if (rotXField.IsDirty())
		currentObjectSelected->rot.x = rotXField.GetValue();

	if (rotYField.IsDirty())
		currentObjectSelected->rot.y = rotYField.GetValue();

	if (rotZField.IsDirty())
		currentObjectSelected->rot.z = rotZField.GetValue();

	ofVec3f rot = currentObjectSelected->rot;

	if (!rotXField.IsFocus())
		rotXField.SetValue(rot.x);

	if (!rotYField.IsFocus())
		rotYField.SetValue(rot.y);

	if (!rotZField.IsFocus())
		rotZField.SetValue(rot.z);
}

void TransformGui::UpdateScale(BaseObject* currentObjectSelected)
{
	if (scaleXField.IsDirty())
		currentObjectSelected->scale.x = scaleXField.GetValue();

	if (scaleYField.IsDirty())
		currentObjectSelected->scale.y = scaleYField.GetValue();

	if (scaleZField.IsDirty())
		currentObjectSelected->scale.z = scaleZField.GetValue();

	ofVec3f scale = currentObjectSelected->scale;

	if (!scaleXField.IsFocus())
		scaleXField.SetValue(scale.x);

	if (!scaleYField.IsFocus())
		scaleYField.SetValue(scale.y);

	if (!scaleZField.IsFocus())
		scaleZField.SetValue(scale.z);
}

void TransformGui::UpdateColor(BaseObject* currentObjectSelected)
{
	currentObjectSelected->SetColor(colorSlider);
}

void TransformGui::UpdateAlpha(BaseObject* currentObjectSelected)
{

}

bool TransformGui::IsAnyGuiFocused()
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