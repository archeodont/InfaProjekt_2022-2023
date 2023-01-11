#pragma once
#include "biblioteka.h"
class Enemy
{

private:
	//zmienne pocz�tkowe
	int E1Hp[10];
	float x[10],y[10], dx[10], dy[10];
	int frame = 24;
	int xclock = 0;
	int FW[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Texture EnemyTexture;
	Sprite EnemySprite;

public:
	void TexturyPocz�tkowe();
	void ZmiennePoczatkowe(int NumberEnemy);
	Enemy(int NumberEnemy);
	~Enemy();
	void MovePosition();
	void DrawEnemy(RenderWindow& window);
};

