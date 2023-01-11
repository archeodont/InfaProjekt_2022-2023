#pragma once
#include "biblioteka.h"

// deklaracja klasy Starship
class Starship
{
	//funkcje publiczne klasy Starship
public:
	void ZmiennePocz¹tkowe();
	Starship();
	~Starship();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	void Drawstarship(RenderWindow& window);

	//funkcje prywatne klasy Starship
private:
	Texture StarshipTexture;
	Sprite StarshipSprite;
	int x, dx, y, dy,Dmg,SHp;
	const int width = 1280;
	const int height = 720;
};

