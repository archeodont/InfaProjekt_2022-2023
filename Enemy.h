#pragma once
#include "biblioteka.h"
#include "Starship.h"
#include "Pocisk.h"

class Enemy
{

private:
	//zmienne pocz�tkowe
	
	float x[10], y[10], dx[10], dy[10];
	int frame = 24;
	int xclock = 0;
	int FW[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Texture EnemyTexture;

public:

	int E1Hp[10];
	int SumaHp=1;
	int dmg,AllDMG = 0;
	Sprite EnemySprite;
	void TexturyPocz�tkowe();
	void ZmiennePoczatkowe(int NumberEnemy);
	Enemy(int NumberEnemy);
	~Enemy();
	void MovePosition();
	void DrawEnemy(RenderWindow& window, Starship& starship,int gra, Pocisk& pocisk);
	int ZeroEnemy();
	int DMGdealtToEnemy()
	{
		return AllDMG;
	}
};