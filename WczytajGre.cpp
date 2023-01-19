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



void Wczytajgre::DownloadDataToGame(string filename,Starship& starship,Enemy& enemy)
{
	
	ifstream inFile;
	inFile.open(filename);
	int i = 1;
	string line;
	while (getline(inFile, line))
	{
		if (i == 1) enemy.E1Hp[0] = stoi(line);
		else if (i == 2) enemy.E1Hp[1] = stoi(line);
		else if (i == 3) enemy.E1Hp[2] = stoi(line);
		else if (i == 4) enemy.E1Hp[3] = stoi(line);
		else if (i == 5) enemy.E1Hp[4] = stoi(line);
		else if (i == 6) enemy.E1Hp[5] = stoi(line);
		else if (i == 7) enemy.E1Hp[6] = stoi(line);
		else if (i == 8) enemy.E1Hp[7] = stoi(line);
		else if (i == 9) enemy.E1Hp[8] = stoi(line);
		else if (i == 10) enemy.E1Hp[9] = stoi(line);
		else if (i == 11) starship.SHp = stoi(line);
		else if (i == 12) starship.score = stoi(line);
		i++;	
	}
	for (int j = 0; j < 10; j++)
	{
		cout << enemy.E1Hp[j] << "\n";
	}
	cout << starship.SHp << "\n" << starship.score << "\n";
	starship.MaxSHp = starship.SHp;
	enemy.AllDMG = starship.score;
	inFile.close();
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

Wczytajgre::~Wczytajgre()
{
	
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
	}
}

