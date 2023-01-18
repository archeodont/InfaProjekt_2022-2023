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
	int x, dx, y, dy;
	int score = 0;
	int SHp = 1001;
	int MaxSHp = 1001;
	
	Sprite StarshipSprite;
	//funkcje prywatne klasy Starship
private:
	Texture StarshipTexture;
	const int width = 1280;
	const int height = 720;
};

