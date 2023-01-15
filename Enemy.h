#pragma once
#include "biblioteka.h"
#include "Starship.h"

class Enemy
{

private:
	//zmienne pocz¹tkowe
	int E1Hp[10];
	float x[10], y[10], dx[10], dy[10];
	int frame = 24;
	int xclock = 0;
	int FW[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Texture EnemyTexture;

public:
	int dmg;
	Sprite EnemySprite;
	void TexturyPocz¹tkowe();
	void ZmiennePoczatkowe(int NumberEnemy);
	Enemy(int NumberEnemy);
	~Enemy();
	void MovePosition();
	void DrawEnemy(RenderWindow& window, Starship& starship,int gra);

};