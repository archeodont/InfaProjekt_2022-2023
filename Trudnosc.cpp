#include "Trudnosc.h"

Trudnosc::Trudnosc()
{
	if (!font.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";

	PoziomTrudnosci[0].setFont(font);
	PoziomTrudnosci[0].setFillColor(Color::Color(255, 215, 0));
	PoziomTrudnosci[0].setString("Latwy");
	PoziomTrudnosci[0].setCharacterSize(50);
	PoziomTrudnosci[0].setPosition(640 - PoziomTrudnosci[0].getLocalBounds().width / 2, 330);

	PoziomTrudnosci[1].setFont(font);
	PoziomTrudnosci[1].setFillColor(Color::Color(120, 80, 0));
	PoziomTrudnosci[1].setString("Sredni");
	PoziomTrudnosci[1].setCharacterSize(50);
	PoziomTrudnosci[1].setPosition(640 - PoziomTrudnosci[1].getLocalBounds().width / 2, 430);

	PoziomTrudnosci[2].setFont(font);
	PoziomTrudnosci[2].setFillColor(Color::Color(120, 80, 0));
	PoziomTrudnosci[2].setString("Trudny");
	PoziomTrudnosci[2].setCharacterSize(50);
	PoziomTrudnosci[2].setPosition(640 - PoziomTrudnosci[2].getLocalBounds().width / 2, 530);

	PoziomTrudnosci[3].setFont(font);
	PoziomTrudnosci[3].setFillColor(Color::Color(120, 80, 0));
	PoziomTrudnosci[3].setString("Poziom Trudnosci : ");
	PoziomTrudnosci[3].setCharacterSize(70);
	PoziomTrudnosci[3].setPosition(660 - PoziomTrudnosci[3].getLocalBounds().width / 2, 230);

	WybranyPoziom = 0;
}

Trudnosc::~Trudnosc()
{

}


void Trudnosc::drawTrudnosc(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(PoziomTrudnosci[i]);
	}
}

void Trudnosc::MoveUpTrudnosc()
{
	if (WybranyPoziom >= 0 && WybranyPoziom <= 2)
	{
		PoziomTrudnosci[WybranyPoziom].setFillColor(Color::Color(120, 80, 0));

		WybranyPoziom--;
		if (WybranyPoziom < 0) {
			WybranyPoziom = 2;
		}
		PoziomTrudnosci[WybranyPoziom].setFillColor(Color::Color(255, 215, 0));
	}
}

void Trudnosc::MoveDownTrudnosc()
{
	if (WybranyPoziom >= 0 && WybranyPoziom <= 4) {
		PoziomTrudnosci[WybranyPoziom].setFillColor(Color::Color(120, 80, 0));

		WybranyPoziom++;
		if (WybranyPoziom == 3) {
			WybranyPoziom = 0;
		}

		PoziomTrudnosci[WybranyPoziom].setFillColor(Color::Color(255, 215, 0));
	}
}

void Trudnosc::uploadTrudnosc(Event& event, RenderWindow& window)
{
	switch (event.type)
	{

	case Event::KeyPressed:
		if (event.key.code == Keyboard::Up)
		{
			MoveUpTrudnosc();
			break;
		}
		if (event.key.code == Keyboard::Down)
		{
			MoveDownTrudnosc();
			break;
		}
	case Keyboard::Enter:
		if (WybranyPoziom == 0)
		{
			printf("wybrano Poziom trudnosci 1\n");
			break;
		}
		if (WybranyPoziom == 1)
		{
			printf("wybrano Poziom trudnosci 2\n");
			break;
		}
		if (WybranyPoziom == 2)
		{
			printf("wybrano Poziom trudnosci 3\n");
			break;
		}
	}
}
