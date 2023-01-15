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
private:
	int WybranyPoziom;
	Font font;
	Text PoziomTrudnosci[4];

};

