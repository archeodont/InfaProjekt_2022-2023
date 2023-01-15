#pragma once
#include "biblioteka.h"

class Trudnosc
{
public:
	void drawTrudnosc(RenderWindow& window);
	void MoveUpTrudnosc();
	void MoveDownTrudnosc();
	void uploadTrudnosc(Event& event, RenderWindow& window);
	Trudnosc();
	~Trudnosc();
	void Trudnosc1();
	void Trudnosc2();
	void Trudnosc3();
	int WybranyPoziomTrudnosci = 3;
	int WybranypoziomTrudnosci()
	{
		return WybranyPoziomTrudnosci;
	}

private:
	int WybranyPoziom;
	Font font;
	Text PoziomTrudnosci[4];

};

