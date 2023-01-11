#include "Enemy.h"
#include "biblioteka.h"

void Enemy::ZmiennePoczatkowe(int NumberEnemy)
{
	int i = 0;
	for ( i; i < NumberEnemy; i++)
	{
		x[i] = -50 - i * 200;
		y[i] = 0;
		dx[i] = 10;
		dy[i] = 1;
		cout << x[i];
	}
}

Enemy::Enemy(int NumberEnemy)
{
	ZmiennePoczatkowe(NumberEnemy);
}


Enemy::~Enemy()
{
	
}
// funkcja s³uzaca za zmiane pozycji
void Enemy::MovePosition()
{
	
	for (int i = 0; i < 10; i++)
	{
		x[i] += dx[i];
		y[i] += dy[i];
		if ((dy[i] > 0.5) && (dy[i] < 30))
			dy[i] += 0.012 * i;
		if ((dy[i] < -0.5) && (dy[i] > -30))
			dy[i] += 0.006 * i;
		if ((dx[i] > 0.5)&&(dx[i]<30))
			dx[i] += 0.01 * i;
		if(FW[i]<201)
		FW[i]+=1;
			if (((x[i] < 0) && (FW[i]>200)) || (x[i] > 1231))
			{
				dx[i] = -dx[i];
			}
			if ((y[i] > 660)||(y[i]<0))
			{
				dy[i] = -dy[i];
			}
	}
}
//frame == 21;
// funkcja wyswietlajaca wroga
void Enemy::DrawEnemy(RenderWindow& window)
{
	xclock++;
	if (xclock == 8)
		xclock = 0;

	for (int i = 0; i < 10; i++)
	{
		Texture EnemyTexture;
		EnemyTexture.loadFromFile("enemy.png");
		Sprite EnemySprite(EnemyTexture, IntRect(181 + xclock * frame, 220, 23, 23));
		EnemySprite.setScale(3, 3);
		EnemySprite.setPosition(x[i], y[i]);
		window.draw(EnemySprite);
	}
	
}




