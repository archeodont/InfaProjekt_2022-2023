	#include "Starship.h"

// położenie początkowe oraz predkosci zmiany położenia Statku
void Starship::ZmiennePoczątkowe()
{
	x = 600;
	y = 550;
	dx = 15;
	dy = 15;
}

//konstruktor
Starship::Starship()
{
	ZmiennePoczątkowe();
}

//destruktor
Starship::~Starship()
{
}

//Funkcje odpowiedzalne za poruszanie sie statkiem
void Starship::MoveUp()
{
	if (y > 0)
	{
		y -= dy;
	}
}

void Starship::MoveDown()
{
	if (y < 605)
	{
		y += dy;
	}
}

void Starship::MoveLeft()
{
	if (x > 0)
	{
		x -= dx;
	}
}

void Starship::MoveRight()
{
	if (x < 1185)
	{
		x += dx;
	}
}

//rysowanie statku
void Starship::Drawstarship(RenderWindow& window)
{
	Texture StarshipTexture;
	StarshipTexture.loadFromFile("Starship.png");
	Sprite StarshipSprite(StarshipTexture, IntRect(50, 45, 100, 110));

	StarshipSprite.setPosition(x,y);
	window.draw(StarshipSprite);
}
