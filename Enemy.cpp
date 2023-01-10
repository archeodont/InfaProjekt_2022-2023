#include "Enemy.h"
#include "biblioteka.h"

void Enemy::ZmiennePoczatkowe()
{
	for(int i = 0; i < 20;i++)
	{
		x[i] = -400;
		y[i] = 0;
		dx[i] = 10;
		dy[i] = 10;
	}
}

Enemy::Enemy()
{
	ZmiennePoczatkowe();
}

void Enemy::MakeEnemy()
{
	for (int i = 0; i < 10; i++)
	{

	}
}

Enemy::~Enemy()
{

}
// funkcja s³uzaca za zmiane pozycji
void Enemy::MovePosition()
{
	for (int i = 0; i < 20; i++)
	{
		x[i] += dx[i];
		if (((x[i] < 0) && (y[i] > 25)) || (x[i] > 1231))
		{
			dx[i] = -dx[i];
			y[i] += 45;
		}
		if (y[i] > 650)
		{
			{
				
			}
		}
	}
}
//frame == 21;
// funkcja wyswietlajaca wroga
void Enemy::DrawEnemy(RenderWindow& window)
{
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

void Enemy::xClock()
{	
	xclock++;
	if (xclock == 8)
		xclock = 0;
	if (xclock == 0)
		cout << "xclock = 0\n";
	else
		cout << "xclock = " << xclock << endl;
}


