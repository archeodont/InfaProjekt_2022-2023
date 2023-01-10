#pragma once
#include "biblioteka.h"
class Enemy
{

private:
	//Pozycje wrogów
	int x[10];
	int y[10];

	//predkosc ruchu wrogów
	int dx = 5;
	int dy = 5;


public:

	void SetStartPosition();
	Enemy();
	~Enemy();
	void MovePosition();
	void DrawEnemy();
	

};

