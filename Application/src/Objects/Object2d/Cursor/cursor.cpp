#include "cursor.h"
// Constructeur de la classe Cursor avec chemin d'acc�s au fichier
Cursor::Cursor(const std::string fileptah)
	: Image(0.0f, 0.0f, 0.0f, fileptah)
	, show(false)
{
}
// Destructeur de la classe Cursor
Cursor::~Cursor()
{
}
// Fonction permettant l'initialisation des param�tres du curseur
void Cursor::Setup()
{
	
}
// Fonction permettant la mise � jour des param�tres du curseur
void Cursor::Update()
{
}
// Fonction permettant l'affichage du curseur � l'�cran 
void Cursor::Draw()
{
	// S'il est visible, on l'affiche � sa position actuelle
	if (show)
	{
		image->draw(pos.x - image->getWidth() * 0.5f, pos.y - image->getHeight() * 0.5f, image->getWidth(), image->getHeight());
	}
}