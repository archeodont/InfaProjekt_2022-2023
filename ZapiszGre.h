#pragma once
#include "biblioteka.h"

class Zapiszgre
{
public:

	void drawZapisz(RenderWindow& window);
	void MoveUpZapisz();
	void MoveDownZapisz();
	void uploadZapisz(Event& event, RenderWindow& window);
	Zapiszgre();
	~Zapiszgre();

private:


	int WybranyZapis ;
	Font font;
	Text Zapis[4];
	
};

