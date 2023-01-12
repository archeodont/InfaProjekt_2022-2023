#include "WczytajGre.h"

Wczytajgre::Wczytajgre()
{
	if (!font.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";

	Wczytaj[0].setFont(font);
	Wczytaj[0].setFillColor(Color::Color(255, 215, 0));
	Wczytaj[0].setString("Wczytaj 1");
	Wczytaj[0].setCharacterSize(50);
	Wczytaj[0].setPosition(640 - Wczytaj[0].getLocalBounds().width / 2, 240);

	Wczytaj[1].setFont(font);
	Wczytaj[1].setFillColor(Color::Color(120, 80, 0));
	Wczytaj[1].setString("Wczytaj 2");
	Wczytaj[1].setCharacterSize(50);
	Wczytaj[1].setPosition(640 - Wczytaj[1].getLocalBounds().width / 2, 340);

	Wczytaj[2].setFont(font);
	Wczytaj[2].setFillColor(Color::Color(120, 80, 0));
	Wczytaj[2].setString("Wczytaj 3");
	Wczytaj[2].setCharacterSize(50);
	Wczytaj[2].setPosition(640 - Wczytaj[2].getLocalBounds().width / 2, 440);

	Wczytaj[3].setFont(font);
	Wczytaj[3].setFillColor(Color::Color(120, 80, 0));
	Wczytaj[3].setString("Wczytaj 4");
	Wczytaj[3].setCharacterSize(50);
	Wczytaj[3].setPosition(640 - Wczytaj[3].getLocalBounds().width / 2, 540);

	WybranyWczytaj = 0;
}

Wczytajgre::~Wczytajgre()
{

}

void Wczytajgre::drawWczytaj(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(Wczytaj[i]);
	}
}

void Wczytajgre::MoveUpWczytaj()
{
	if (WybranyWczytaj >= 0 && WybranyWczytaj <= 3)
	{
		Wczytaj[WybranyWczytaj].setFillColor(Color::Color(120, 80, 0));

		WybranyWczytaj--;
		if (WybranyWczytaj < 0) {
			WybranyWczytaj = 3;
		}
		Wczytaj[WybranyWczytaj].setFillColor(Color::Color(255, 215, 0));
	}
}

void Wczytajgre::MoveDownWczytaj()
{
	if (WybranyWczytaj >= 0 && WybranyWczytaj <= 5) {
		Wczytaj[WybranyWczytaj].setFillColor(Color::Color(120, 80, 0));

		WybranyWczytaj++;
		if (WybranyWczytaj == 4) {
			WybranyWczytaj = 0;
		}

		Wczytaj[WybranyWczytaj].setFillColor(Color::Color(255, 215, 0));
	}
}

void Wczytajgre::uploadWczytaj(Event& event, RenderWindow& window)
{
	switch (event.type)
	{

	case Event::KeyPressed:
		if (event.key.code == Keyboard::Up)
		{
			MoveUpWczytaj();
			break;
		}
		if (event.key.code == Keyboard::Down)
		{
			MoveDownWczytaj();
			break;
		}
	case Keyboard::Enter:
		if (WybranyWczytaj == 0)
		{
			printf("Wczytano zapis 1\n");
			break;
		}
		if (WybranyWczytaj == 1)
		{
			printf("Wczytano zapis 2\n");
			break;
		}
		if (WybranyWczytaj == 2)
		{
			printf("Wczytano zapis 3\n");
			break;
		}
		if (WybranyWczytaj == 3)
		{
			printf("Wczytano zapis 4\n");
			break;
		}
	}
}

