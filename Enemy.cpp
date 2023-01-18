#include "Enemy.h"
#include "biblioteka.h"


//Ustawia wartosci poczatkowe wrogom
void Enemy::ZmiennePoczatkowe(int NumberEnemy)
{
	int i = 0;
	for ( i; i < NumberEnemy; i++)
	{
		E1Hp[i] = 99;
		x[i] = -50 - i * 200;
		y[i] = 0;
		dx[i] = 10;
		dy[i] = 1;
	}
}
void Enemy::TexturyPocz¹tkowe()
{
	EnemyTexture.loadFromFile("enemy.png");
	EnemySprite.setTexture(EnemyTexture);
	EnemySprite.setScale(3, 3);
}

//konstruktor
Enemy::Enemy(int NumberEnemy)
{
	ZmiennePoczatkowe(NumberEnemy);
	TexturyPocz¹tkowe();
}

//destruktor
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
		if ((dy[i] > 0.5) && (dy[i] < 25))
			dy[i] += 0.0008 * i;
		if ((dy[i] < -0.5) && (dy[i] > -25))
			dy[i] += 0.0002 * i;
		if ((dx[i] > 0.5)&&(dx[i]<25))
			dx[i] += 0.0008 * i;
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

int Enemy::ZeroEnemy()
{
	return SumaHp;
}

// funkcja wyswietlajaca wroga
void Enemy::DrawEnemy(RenderWindow& window, Starship& starship,int gra,Pocisk& pocisk)
{
	xclock++;
	if (xclock == 8)
		xclock = 0;

	for (int i = 0; i < 10; i++)
	{
		if (E1Hp[i] > 0)
		{
			EnemySprite.setTextureRect(IntRect(181 + xclock * frame, 220, 23, 23));
			EnemySprite.setPosition(x[i], y[i]);
		}
		FloatRect rect2 = EnemySprite.getGlobalBounds();
		FloatRect rect1 = starship.StarshipSprite.getGlobalBounds();
		if ((rect1.intersects(rect2)) && gra == 1)
		{
			cout << "zadano dmg \n";
			dmg++;
		}
		for (int k = 0; k < 20; k++)
		{
			pocisk.SpritePocisk.setPosition(pocisk.Px[k], pocisk.Py[k]);
			FloatRect rect3 = pocisk.SpritePocisk.getGlobalBounds();
			if ((rect3.intersects(rect2)) && gra == 1)
			{
				cout << "zadano dmg Wrogowi \n";
				E1Hp[i] -= 10;
				pocisk.SendAwayPocisk(k);
				AllDMG += 10;
			}
		}
		SumaHp = 0;
			if (E1Hp[i] < 0)
				E1Hp[i] = 0;
				
			for (int j = 0; j < 10; j++)
				SumaHp += E1Hp[j];

			if(SumaHp==0)
				EnemySprite.setPosition(-2000, -2000);
		if (E1Hp[i] > 0)
		{
			window.draw(EnemySprite);
		}
	}
	
}
