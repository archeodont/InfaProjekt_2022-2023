#pragma once
#include "biblioteka.h"
#include "Starship.h"
#include "Enemy.h"

class Wczytajgre
{
public:

	void drawWczytaj(RenderWindow& window);
	void MoveUpWczytaj();
	void MoveDownWczytaj();
	void uploadWczytaj(Event& event, RenderWindow& window);
	Wczytajgre();
	~Wczytajgre();
	void DownloadDataToGame(string filename, Starship& starship, Enemy& enemy);
	int WczytajPressed()
	{
		return WybranyWczytaj;
	}

private:

	int WybranyWczytaj;
	Font font;
	Text Wczytaj[4];
};

