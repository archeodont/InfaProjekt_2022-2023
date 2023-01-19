#include "ZapiszGre.h"

Zapiszgre::Zapiszgre()
{
	if (!font.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";

	Zapis[0].setFont(font);
	Zapis[0].setFillColor(Color::Color(255, 215, 0));
	Zapis[0].setString("Zapis 1");
	Zapis[0].setCharacterSize(50);
	Zapis[0].setPosition(640 - Zapis[0].getLocalBounds().width / 2, 240);

	Zapis[1].setFont(font);
	Zapis[1].setFillColor(Color::Color(120, 80, 0));
	Zapis[1].setString("Zapis 2");
	Zapis[1].setCharacterSize(50);
	Zapis[1].setPosition(640 - Zapis[1].getLocalBounds().width / 2, 340);

	Zapis[2].setFont(font);
	Zapis[2].setFillColor(Color::Color(120, 80, 0));
	Zapis[2].setString("Zapis 3");
	Zapis[2].setCharacterSize(50);
	Zapis[2].setPosition(640 - Zapis[2].getLocalBounds().width / 2, 440);

	Zapis[3].setFont(font);
	Zapis[3].setFillColor(Color::Color(120, 80, 0));
	Zapis[3].setString("Zapis 4");
	Zapis[3].setCharacterSize(50);
	Zapis[3].setPosition(640 - Zapis[3].getLocalBounds().width / 2, 540);

	WybranyZapis = 0;
}

Zapiszgre::~Zapiszgre()
{

}

void Zapiszgre::ClockRestart()
{
	clockZapis.restart();	
}

int Zapiszgre::ClockTime()
{
	timeZapis = clockZapis.getElapsedTime();
	return timeZapis.asMilliseconds();
}

void Zapiszgre::DownloadDataToSave(int EHp[10], int SSHp, int SSscore, string filename)
{
	ofstream outFile;
	outFile.open(filename);
	for (int i = 0; i < 10; i++)
	{
		outFile << EHp[i] << "\n";
	}
	outFile << SSHp << "\n" << SSscore << endl;
	outFile.close();
}


void Zapiszgre::drawZapisz(RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(Zapis[i]);
	}
}

void Zapiszgre::MoveUpZapisz()
{
	if (WybranyZapis >= 0 && WybranyZapis <= 3) 
	{
		Zapis[WybranyZapis].setFillColor(Color::Color(120, 80, 0));

		WybranyZapis--;
		if (WybranyZapis < 0) {
			WybranyZapis = 3;
		}
		Zapis[WybranyZapis].setFillColor(Color::Color(255, 215, 0));
	}
}

void Zapiszgre::MoveDownZapisz()
{
	if (WybranyZapis >= 0 && WybranyZapis <= 5) {
		Zapis[WybranyZapis].setFillColor(Color::Color(120, 80, 0));

		WybranyZapis++;
		if (WybranyZapis == 4) {
			WybranyZapis = 0;
		}
		
		Zapis[WybranyZapis].setFillColor(Color::Color(255, 215, 0));
	}
}

void Zapiszgre::uploadZapisz(Event& event, RenderWindow& window)
{
	switch (event.type)
	{

	case Event::KeyPressed:
		if (event.key.code == Keyboard::Up)
		{
			MoveUpZapisz();
			break;
		}
		if (event.key.code == Keyboard::Down)
		{
			MoveDownZapisz();
			break;
		}
	}
}

