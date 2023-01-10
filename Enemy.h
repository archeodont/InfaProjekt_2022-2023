#pragma once
#include "biblioteka.h"
class Enemy
{

private:
	//zmienne pocz¹tkowe
	int x[20], y[20];
	int dx[20], dy[20];
	int frame = 24;
	int xclock = 0;
	Texture EnemyTexture[20];
	Sprite EnemySprite[20];

public:

	void ZmiennePoczatkowe();
	Enemy();
	~Enemy();
	void MakeEnemy();
	void MovePosition();
	void DrawEnemy(RenderWindow& window);
	void xClock();

};

