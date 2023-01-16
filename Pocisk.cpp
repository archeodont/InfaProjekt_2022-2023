#include "Pocisk.h"

void Pocisk::TexturyPoczatkowePocisku()
{
	TexturePocisk.loadFromFile("pocisk.png");
	SpritePocisk.setTexture(TexturePocisk);
	SpritePocisk.setScale(1.5, 1.5);
}

void Pocisk::ZmiennePoczatkowePocisku(int K)
{
	for (int i = 0; i < K; i++)
	{
		Px[i] = -300;
		Py[i] = -300;
		Pdx[i] = 5;
		Pdy[i] = 5;
	}
}

void Pocisk::MovePocisk()
{
	for (int i = 0; i < 20; i++)
	{
		Py[i] -= Pdy[i];
	}
}


void Pocisk::uploadPocisk()
{
	
	MovePocisk();
}

Pocisk::Pocisk(int K)
{
	TexturyPoczatkowePocisku();
	ZmiennePoczatkowePocisku(K);
}

Pocisk::~Pocisk()
{
}

void Pocisk::DrawPocisk(RenderWindow& window)
{
	for (int i = 0; i < 20; i++)
	{
		SpritePocisk.setPosition(Px[i], Py[i]);
		window.draw(SpritePocisk) ;
	}
}

void Pocisk::SummonPocisk(Starship& starship)
{
	time = clock.getElapsedTime();
	if(time.asSeconds()>0.2)
	{
		clock.restart();
		Px[WybranyPocisk] = 5 + starship.x + (WybranyPocisk % 2) * 30;
		Py[WybranyPocisk] = starship.y - 20;

		WybranyPocisk++;
		if (WybranyPocisk == 20)
			WybranyPocisk = 0;
	}
}

void Pocisk::SendAwayPocisk(int nr)
{
	Px[nr] = -300;
	Py[nr] = -300;
}
