#pragma once
#include "biblioteka.h"

class Wczytajgre
{
public:

	void drawWczytaj(RenderWindow& window);
	void MoveUpWczytaj();
	void MoveDownWczytaj();
	void uploadWczytaj(Event& event, RenderWindow& window);
	Wczytajgre();
	~Wczytajgre();

private:

	int WybranyWczytaj;
	Font font;
	Text Wczytaj[4];
};

