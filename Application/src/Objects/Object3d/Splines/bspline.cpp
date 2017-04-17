#include "bspline.h"

#include "../../application.h"

// Constructeur de la classe Image avec chemin de fichier en paramètre
BSpline::BSpline()
	: BaseObject(0.0f, 0.0f, 0.0f)
{
	Load();

}
// Constructeur de la classe Image avec 3 positions et un chemin de fichier en paramètres
BSpline::BSpline(float x, float y, float z)
	: BaseObject(x, y, z)
{
	Load();
}
// Destructeur de la classe Image
BSpline::~BSpline()
{
	if (nullptr != firstCubic)
	{
		delete firstCubic;
		firstCubic = nullptr;
	}

	if (nullptr != secondCubic)
	{
		delete secondCubic;
		secondCubic = nullptr;
	}
}
// Fonction permettant de charger une image
void BSpline::Load()
{
	firstCubic = new Cubic(-350.0f, 0.0f, 0.0f);
	secondCubic = new Cubic(350.0f, 0.0f, 0.0f);

	// Initialisation de l'image
	Setup();
}
// Fonction permettant l'initialisation de paramètres de l'image
void BSpline::Setup()
{
	firstCubic->ReplaceLastNodeBy(secondCubic->GetFirstNode());
}

void BSpline::reset()
{

}

// Fonction permettant la mise à jour des paramètres de l'image
void BSpline::Update()
{
	firstCubic->Update();
	secondCubic->Update();
}
// Fonction permettant le rendu graphique de l'image
void BSpline::Draw()
{
	firstCubic->Draw();
	secondCubic->Draw();
}
// Fonction permettant de déterminer les frontières d'une image
void BSpline::DrawBoundingBox()
{
	firstCubic->DrawBoundingBox();
	secondCubic->DrawBoundingBox();
}
// Fonction permettant d'ajuster la teinte des pixels de l'image
void BSpline::SetColor(int r, int g, int b, int a)
{
	BaseObject::SetColor(r, g, b, a);
}
// Fonction permettant d'ajuster la composante de transparence de l'image
void BSpline::SetAlpha(int a)
{

}
// Détermination de la collision entre le clic de la souris et l'image 
bool BSpline::CheckPointCollision(const ofVec3f& mouse, const ofVec3f& objScreenPos)
{
	return false;
}

