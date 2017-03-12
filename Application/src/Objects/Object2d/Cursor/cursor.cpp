#include "cursor.h"
// Constructeur de la classe Cursor avec chemin d'accès au fichier
Cursor::Cursor(const std::string fileptah)
	: Image(0.0f, 0.0f, 0.0f, fileptah)
	, show(false)
{
}
// Destructeur de la classe Cursor
Cursor::~Cursor()
{
}
// Fonction permettant l'initialisation des paramètres du curseur
void Cursor::Setup()
{
	
}
// Fonction permettant la mise à jour des paramètres du curseur
void Cursor::Update()
{
}
// Fonction permettant l'affichage du curseur à l'écran 
void Cursor::Draw()
{
	// S'il est visible, on l'affiche à sa position actuelle
	if (show)
	{
		image->draw(pos.x - image->getWidth() * 0.5f, pos.y - image->getHeight() * 0.5f, image->getWidth(), image->getHeight());
	}
}