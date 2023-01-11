#pragma once
#include "biblioteka.h"
class Enemy
{

private:
	//zmienne pocz¹tkowe
	float x[10],y[10], dx[10], dy[10];
	int frame = 24;
	int xclock = 0;
	int FW[10] = { 0,0,0,0,0,0,0,0,0,0 };
	Texture EnemyTexture[10];
	Sprite EnemySprite[10];

public:

	void ZmiennePoczatkowe(int NumberEnemy);
	Enemy(int NumberEnemy);
	~Enemy();
	void MovePosition();
	void DrawEnemy(RenderWindow& window);
};

