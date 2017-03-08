#include "cursor.h"

Cursor::Cursor(const std::string fileptah)
	: Image(0.0f, 0.0f, 0.0f, fileptah)
	, show(false)
{
}

Cursor::~Cursor()
{
}

void Cursor::Setup()
{
	
}

void Cursor::Update()
{
}

void Cursor::Draw()
{
	if (show)
	{
		image->draw(pos.x - image->getWidth() * 0.5f, pos.y - image->getHeight() * 0.5f, image->getWidth(), image->getHeight());
	}
}