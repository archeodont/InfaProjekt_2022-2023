#include "Opis.h"

int Opiswidth = 640;
int Opisheight = 210;
int Ohdiff = 50;

Opis::Opis()
{

	if (!fontOpis.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";
	
	textOpis[0].setFont(fontOpis);
	textOpis[0].setString("Zasady gry:");
	textOpis[0].setCharacterSize(60);

	textOpis[1].setFont(fontOpis);
	textOpis[1].setString("Strzalka w lewo - ruch statkiem w lewo");
	textOpis[1].setCharacterSize(30);

	textOpis[2].setFont(fontOpis);
	textOpis[2].setString("Strzalka w prawo - ruch statkiem w prawo");
	textOpis[2].setCharacterSize(30);

	textOpis[3].setFont(fontOpis);
	textOpis[3].setString("Strzalka w gore - ruch statkiem w gore");
	textOpis[3].setCharacterSize(30);

	textOpis[4].setFont(fontOpis);
	textOpis[4].setString("Strzalka w dol - ruch statkiem w dol");
	textOpis[4].setCharacterSize(30);

	textOpis[5].setFont(fontOpis);
	textOpis[5].setString("Spacja - strzal");
	textOpis[5].setCharacterSize(30);

	textOpis[7].setFont(fontOpis);
	textOpis[7].setString("Cel Gry:");
	textOpis[7].setCharacterSize(60);

	textOpis[8].setFont(fontOpis);
	textOpis[8].setString("Pokonaj wszystkich wrogow by przejsc gre, tracac przy tym jak najmniej hp");
	textOpis[8].setCharacterSize(30);
	

	textOpis[9].setFont(fontOpis);
	textOpis[9].setString("W kazdym momencie mozesz wyjsc do menu i zapisac gre");
	textOpis[9].setCharacterSize(30);



}

Opis::~Opis()
{
}

void Opis::ZamknijOpis()
{
}

void Opis::DrawOpis(RenderWindow& window, Color& color,int move)
{
	for (int i = 0; i < OpisTextLines; i++)
	{
		textOpis[i].setFillColor(color);
		if (move == 1)
		{
			if(i%7==0)
				textOpis[i].setPosition(Opiswidth - textOpis[i].getLocalBounds().width / 2.f, Opisheight + Ohdiff * i - 130);
			else
				textOpis[i].setPosition(Opiswidth - textOpis[i].getLocalBounds().width / 2.f, -100 + Opisheight + Ohdiff * i);
		}
		if (move == 0)
		{
			if (i % 7 == 0)
				textOpis[i].setPosition(Opiswidth - textOpis[i].getLocalBounds().width / 2.f, Opisheight + Ohdiff * i - 30);
			else
				textOpis[i].setPosition(Opiswidth - textOpis[i].getLocalBounds().width / 2.f,  + Opisheight + Ohdiff * i);
		}
		window.draw(textOpis[i]);
	}
}
