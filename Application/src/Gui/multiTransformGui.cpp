#include "multiTransformGui.h"

#include <limits>
// Constructeur de la classe MultiTransformGui sans param�tre avec initialisation
MultiTransformGui::MultiTransformGui()
	: BaseGui()
	, pos(ofVec3f(0.0f, 0.0f, 0.0f))
	, rot(ofVec3f(0.0f, 0.0f, 0.0f))
	, scale(ofVec3f(0.0f, 0.0f, 0.0f))
{
}
// Destructeur de la classe MultiTransformGui
MultiTransformGui::~MultiTransformGui()
{
}
// Fonction permettant l'initialisation de l'interface de transformation multiple 
void MultiTransformGui::Setup()
{
	BaseGui::Setup();
	// Initialisation des options propos�es par l'interface
	gui.setup();
	// Param�tres de position pour translation
	gui.add(posXField.setup("PosX:", 0, -1000, 1000));
	gui.add(posYField.setup("PosY:", 0, -1000, 1000));
	gui.add(posZField.setup("PosZ:", 0, -1000, 1000));
	// Param�tres de rotation
	gui.add(rotXField.setup("RotX:", 0, 0, 359));
	gui.add(rotYField.setup("RotY:", 0, 0, 359));
	gui.add(rotZField.setup("RotZ:", 0, 0, 359));
	// Param�tres de proportion
	gui.add(scaleXField.setup("ScaleX:", 1.0f, 0, 200));
	gui.add(scaleYField.setup("ScaleY:", 1.0f, 0, 200));
	gui.add(scaleZField.setup("ScaleZ:", 1.0f, 0, 200));
}
// Fonction permettant la mise � jour de l'interface de transformation multiple
void MultiTransformGui::Update(std::vector<BaseObject*>& currentObjectSelected)
{
	// Mise � jour des transformations des objets s�lectionn�s
	UpdatePosition(currentObjectSelected);
	UpdateRotation(currentObjectSelected);
	UpdateScale(currentObjectSelected);
}
// Fonction permettant la mise � jour de la position de l'objet dans l'interface
void MultiTransformGui::UpdatePosition(std::vector<BaseObject*>& currentObjectSelected)
{
	// Si la position a chang�e, on r�cup�re la nouvelle position
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
// Fonction permettant la mise � jour de la rotation de l'objet dans l'interface
void MultiTransformGui::UpdateRotation(std::vector<BaseObject*>& currentObjectSelected)
{
	// Si la rotation a chang�e, on r�cup�re la nouvelle rotation
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
// Fonction permettant la mise � jour de la proportion sur l'interface de transformation
void MultiTransformGui::UpdateScale(std::vector<BaseObject*>& currentObjectSelected)
{
	// Si la proportion a chang�e, on r�cup�re la nouvelle proportion
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
// Fonction permettant validant si un param�tre de l'interface est en modification
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