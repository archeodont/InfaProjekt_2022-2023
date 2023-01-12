#include "Opis.h"

int Opiswidth = 640;
int Opisheight = 210;
int Ohdiff = 50;

Opis::Opis()
{
	int xd=100,yd=100,ydd=50;

	if (!fontOpis.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";
	for (int i = 0; i < OpisTextLines; i++)
	{
		textOpis[i].setFont(fontOpis);
		textOpis[i].setFillColor(Color::Color(255, 215, 0));
		textOpis[i].setCharacterSize(40);
		textOpis[i].setPosition(xd,yd*ydd);
	}
	textOpis[0].setFont(fontOpis);
	textOpis[0].setFillColor(Color::Color(120, 80, 0));
	textOpis[0].setString("Zasady gry:");
	textOpis[0].setCharacterSize(60);
	textOpis[0].setPosition(Opiswidth - textOpis[0].getLocalBounds().width / 2.f, Opisheight -30);

	textOpis[1].setFont(fontOpis);
	textOpis[1].setFillColor(Color::Color(120, 80, 0));
	textOpis[1].setString("Strzalka w lewo - ruch statkiem w lewo");
	textOpis[1].setCharacterSize(30);
	textOpis[1].setPosition(Opiswidth - textOpis[1].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 1);

	textOpis[2].setFont(fontOpis);
	textOpis[2].setFillColor(Color::Color(120, 80, 0));
	textOpis[2].setString("Strzalka w prawo - ruch statkiem w prawo");
	textOpis[2].setCharacterSize(30);
	textOpis[2].setPosition(Opiswidth - textOpis[2].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 2);

	textOpis[3].setFont(fontOpis);
	textOpis[3].setFillColor(Color::Color(120, 80, 0));
	textOpis[3].setString("Strzalka w gore - ruch statkiem w gore");
	textOpis[3].setCharacterSize(30);
	textOpis[3].setPosition(Opiswidth - textOpis[3].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 3);

	textOpis[4].setFont(fontOpis);
	textOpis[4].setFillColor(Color::Color(120, 80, 0));
	textOpis[4].setString("Strzalka w dol - ruch statkiem w dol");
	textOpis[4].setCharacterSize(30);
	textOpis[4].setPosition(Opiswidth - textOpis[4].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 4);

	textOpis[5].setFont(fontOpis);
	textOpis[5].setFillColor(Color::Color(120, 80, 0));
	textOpis[5].setString("Spacja - strzal");
	textOpis[5].setCharacterSize(30);
	textOpis[5].setPosition(Opiswidth - textOpis[5].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 5);

	textOpis[7].setFont(fontOpis);
	textOpis[7].setFillColor(Color::Color(120, 80, 0));
	textOpis[7].setString("Cel Gry:");
	textOpis[7].setCharacterSize(60);
	textOpis[7].setPosition(Opiswidth - textOpis[7].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 7-30);

	textOpis[8].setFont(fontOpis);
	textOpis[8].setFillColor(Color::Color(120, 80, 0));
	textOpis[8].setString("Pokonaj wszystkich wrogow by przejsc gre, tracac przy tym jak najmniej hp");
	textOpis[8].setCharacterSize(30);
	textOpis[8].setPosition(Opiswidth - textOpis[8].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 8);

	textOpis[9].setFont(fontOpis);
	textOpis[9].setFillColor(Color::Color(120, 80, 0));
	textOpis[9].setString("W kazdym momencie mozesz wyjsc do menu i zapisac gre");
	textOpis[9].setCharacterSize(30);
	textOpis[9].setPosition(Opiswidth - textOpis[9].getLocalBounds().width / 2.f, Opisheight + Ohdiff * 9);



}

Opis::~Opis()
{
}

void Opis::ZamknijOpis()
{
}

void Opis::DrawOpis(RenderWindow& window)
{
	for (int i = 0; i < OpisTextLines; i++)
	{
		window.draw(textOpis[i]);
	}
}
