#pragma once
#include "biblioteka.h"

#define OpisTextLines 20

class Opis
{

private:
	Font fontOpis;
	Text textOpis[OpisTextLines];

public:
	Opis();
	~Opis();
	void ZamknijOpis();
	void DrawOpis(RenderWindow& window, Color& color,int move);

};

