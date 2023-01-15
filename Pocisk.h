#pragma once
#include "biblioteka.h"
#include "Starship.h"

class Pocisk
{
private:
	


public:
	float Px[20], Py[20], Pdx[20], Pdy[20];
	void TexturyPoczatkowePocisku();
	void ZmiennePoczatkowePocisku(int K);
	void MovePocisk();
	void uploadPocisk();
	Pocisk(int K);
	~Pocisk();
	void DrawPocisk(RenderWindow& window);
	void SummonPocisk(Starship& starship);
	void SendAwayPocisk();

	int WybranyPocisk = 0;

	Texture TexturePocisk;
	Sprite SpritePocisk;
	Clock clock;
	Time time;
};

