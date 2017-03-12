#include "transformGui.h"

#include <limits>
// Constructeur de la classe TransformGui sans paramètre
TransformGui::TransformGui()
	: BaseGui()
{
}
// Destructeur de la classe TransformGui
TransformGui::~TransformGui()
{
}
// Fonction permettant l'initialisation de l'interface de transformation
void TransformGui::Setup()
{
	BaseGui::Setup();
	// Initialisation desvaleurs de paramètres accessibles via l'interface de transformation
	gui.setup();
	// Paramètres de position pour translation
	gui.add(posXField.setup("PosX:", 0, -1000, 1000));
	gui.add(posYField.setup("PosY:", 0, -1000, 1000));
	gui.add(posZField.setup("PosZ:", 0, -1000, 1000));
	// Paramètres de rotation
	gui.add(rotXField.setup("RotX:", 0, 0, 359));
	gui.add(rotYField.setup("RotY:", 0, 0, 359));
	gui.add(rotZField.setup("RotZ:", 0, 0, 359));
	// Paramètres de proportion 
	gui.add(scaleXField.setup("ScaleX:", 1.0f, 0, 200));
	gui.add(scaleYField.setup("ScaleY:", 1.0f, 0, 200));
	gui.add(scaleZField.setup("ScaleZ:", 1.0f, 0, 200));
	// Paramètres liés à la couleur
	gui.add(colorSlider.setup("Color", ofColor::white, ofColor(0, 0, 0, 0), ofColor(255, 255, 255, 255)));
}
// Fonction permettant de récupérer la couleur de l'objet sélectionné
void TransformGui::OnSelected(BaseObject* currentObjectSelected)
{
	// Ajustement des sliders aux couleurs de l'objet
	colorSlider = currentObjectSelected->GetColor();
}
// Fonction permettant la mise à jour de l'interface de transformation
void TransformGui::Update(BaseObject* currentObjectSelected)
{
	// Si un objet est sélectionné, on met à jour ses informations de transformation
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
// Fonction permettant la mise à jour de la position de l'objet dans l'interface
void TransformGui::UpdatePosition(BaseObject* currentObjectSelected)
{
	// Si la position a changée, on récupère la nouvelle position
	if (posXField.IsDirty())
		currentObjectSelected->pos.x = posXField.GetValue();

	if (posYField.IsDirty())
		currentObjectSelected->pos.y = posYField.GetValue();

	if (posZField.IsDirty())
		currentObjectSelected->pos.z = posZField.GetValue();

	ofVec3f pos = currentObjectSelected->pos;
	// On applique les nouvelles valeurs aux champs de l'interface
	if (!posXField.IsFocus())
		posXField.SetValue(pos.x);

	if (!posYField.IsFocus())
		posYField.SetValue(pos.y);

	if (!posZField.IsFocus())
		posZField.SetValue(pos.z);
}
// Fonction permettant la mise à jour de la rotation de l'objet
void TransformGui::UpdateRotation(BaseObject* currentObjectSelected)
{
	// Si la rotation a changée, on récupère la nouvelle rotation
	if (rotXField.IsDirty())
		currentObjectSelected->rot.x = rotXField.GetValue();

	if (rotYField.IsDirty())
		currentObjectSelected->rot.y = rotYField.GetValue();

	if (rotZField.IsDirty())
		currentObjectSelected->rot.z = rotZField.GetValue();

	ofVec3f rot = currentObjectSelected->rot;
	// On ajuste les valeurs de l'interface en fonction des nouvelles valeurs de rotation
	if (!rotXField.IsFocus())
		rotXField.SetValue(rot.x);

	if (!rotYField.IsFocus())
		rotYField.SetValue(rot.y);

	if (!rotZField.IsFocus())
		rotZField.SetValue(rot.z);
}
// Fonction permettant la mise à jour de la proportion sur l'interface de transformation
void TransformGui::UpdateScale(BaseObject* currentObjectSelected)
{
	// Si la proportion a changée, on récupère la nouvelle proportion
	if (scaleXField.IsDirty())
		currentObjectSelected->scale.x = scaleXField.GetValue();

	if (scaleYField.IsDirty())
		currentObjectSelected->scale.y = scaleYField.GetValue();

	if (scaleZField.IsDirty())
		currentObjectSelected->scale.z = scaleZField.GetValue();

	ofVec3f scale = currentObjectSelected->scale;
	// On ajuste les valeurs de l'interface en fonction des nouvelles valeurs de proportion
	if (!scaleXField.IsFocus())
		scaleXField.SetValue(scale.x);

	if (!scaleYField.IsFocus())
		scaleYField.SetValue(scale.y);

	if (!scaleZField.IsFocus())
		scaleZField.SetValue(scale.z);
}
// Fonction permettant la mise à jour de la couleur sur l'interface de transformation
void TransformGui::UpdateColor(BaseObject* currentObjectSelected)
{
	// On ajuste les valeurs de l'interface en fonction des couleurs de l'objet sélectionné
	currentObjectSelected->SetColor(colorSlider);
}
// Fonction permettant la mise à jour du paramètre alpha de la couleur dans l'interface
void TransformGui::UpdateAlpha(BaseObject* currentObjectSelected)
{

}
// Fonction permettant validant si un paramètre de l'interface est en modification
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