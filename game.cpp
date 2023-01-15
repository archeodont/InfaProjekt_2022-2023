#include "biblioteka.h"
#include "game.h"
#include "windows.h" 


//konstruktor
Game::Game()
{	//Tworzenie zmiennych statystyk
	if (!font.loadFromFile("czcionka.ttf"))
	{
		cout << "Nie wykryto pliku arial";
	}

	//tekst statystyk ilosci HP
	StarshipHealth.setFont(font);
	StarshipHealth.setFillColor(Color::White);
	StarshipHealth.setString("Zycie: " + to_string(SHp));
	StarshipHealth.setCharacterSize(30);
	StarshipHealth.setPosition(1270 - StarshipHealth.getLocalBounds().width-20, 1);

	//tekst statystyk iloœci punktów
	TimeInGame.setFont(font);
	TimeInGame.setFillColor(Color::White);
	TimeInGame.setString("Czas: "+ to_string(score));
	TimeInGame.setCharacterSize(30);
	TimeInGame.setPosition(1270 - TimeInGame.getLocalBounds().width-64, 31);
	
	//pobieranie t³a menu
	MenuTexture.loadFromFile("tlo.png");
	MenuSprite.setTexture(MenuTexture);
	MenuSprite.setScale(1.7,1);
	MenuSprite.setTextureRect(IntRect(0,280,1280,720));
	
	//pobieranie t³a w grze
	GameTexture.loadFromFile("tlogra.png");
	GameSprite.setTexture(GameTexture);
	GameSprite.setScale(1.3, 1.3);

	//pobieranie 5 Asteroid
	AsteroidTexture1.loadFromFile("Asteroida1.png");
	AsteroidSprite1.setTexture(AsteroidTexture1);

	AsteroidTexture2.loadFromFile("Asteroida2.png");
	AsteroidSprite2.setTexture(AsteroidTexture2);

	AsteroidTexture3.loadFromFile("Asteroida3.png");
	AsteroidSprite3.setTexture(AsteroidTexture3);

	AsteroidTexture4.loadFromFile("Asteroida4.png");
	AsteroidSprite4.setTexture(AsteroidTexture4);

	AsteroidTexture5.loadFromFile("Asteroida5.png");
	AsteroidSprite5.setTexture(AsteroidTexture5);

	//ustawianie pozycji pocz¹tkowej asteroid
	for (int i = 0; i < 20; i++)
	{
		Ax[i] = rand() % 1200;
		Ay[i] = -rand() % 400;
		Ady[i] = rand() % 10;
	}
}

//destruktor
Game::~Game()
{

}

//Funkcja Ustalania po³o¿enia asteroid
void Game::AsteroidMove()
{
	for (int i = 0; i < 20; i++)
	{
		Ay[i] += Ady[i];
		if (Ay[i] > 1000)
		{
			Ax[i] = rand() % 1200;
			Ay[i] = -100 -rand() % 300;
		}
	}
}

// Funkcja rysowania asteroid w tle
void Game::AsteroidDraw(RenderWindow& window)
{	
	for (int i = 0; i < 20; i++)
	{
		if (i%5 == 0)
		{
			AsteroidSprite1.setPosition(Ax[i], Ay[i]);
			window.draw(AsteroidSprite1);
		}
		if (i%5 == 1)
		{
			AsteroidSprite2.setPosition(Ax[i], Ay[i]);
			window.draw(AsteroidSprite2);
		}
		if (i%5 == 2)
		{
			AsteroidSprite3.setPosition(Ax[i], Ay[i]);
			window.draw(AsteroidSprite3);
		}
		if (i%5 == 3)
		{
			AsteroidSprite4.setPosition(Ax[i], Ay[i]);
			window.draw(AsteroidSprite4);
		}
		if (i%5 == 4)
		{
			AsteroidSprite5.setPosition(Ax[i], Ay[i]);
			window.draw(AsteroidSprite5);
		}
	}
}



// funkcja aktualizuj¹ca statystyki
void Game::updateStatistic()
{
	StarshipHealth.setString("Health: " + to_string(SHp));
	TimeInGame.setString("Score: " + to_string(score));
}

// funkcja rysuj¹ca statystyki
void Game::StatisticDraw(RenderWindow& window)
{
	window.draw(StarshipHealth);
	window.draw(TimeInGame);
}

// rysowanie t³a w menu
void Game::DrawBackground(RenderWindow& window)
{
	window.draw(MenuSprite);
}
//rysowanie t³a w grze
void Game::DrawBackgroundGame(RenderWindow& window)
{	
	window.draw(GameSprite);
}

// funkcjie odpowiedzialne za przemieszczanie siê pomiêdzy etapami gra,menu,koniec gry
void Game::StageControl(Event& event,RenderWindow& window, MainMenu& mainMenu,Starship& starship)
{
	int x = mainMenu.MainMenuPressed();
	switch (gameStage)
	{
	case stage::menu:
	{
		switch (event.type)
		{
		case Event::KeyPressed:
		{
			if ((x == 0) && (event.key.code == Keyboard::Enter))
			{
				//komenda rozpoczynaj¹ca gre
				gameStage = stage::gra;
				break;
			}
			if ((x == 1) && (event.key.code == Keyboard::Enter))
			{
				//komenda otwieraj¹ca zapis gry
				gameStage = stage::ZapiszGre;
				break;
			}
			if ((x == 2) && (event.key.code == Keyboard::Enter))
			{
				//komenda otwierajaca wczytanie gry
				gameStage = stage::WczytajGre;
				break;
			}
			if ((x == 3) && (event.key.code == Keyboard::Enter))
			{
				//komenda otwierajaca TrudnoscGry
				gameStage = stage::TrudnoscGry;
				break;
			}
			if ((x == 4) && (event.key.code == Keyboard::Enter))
			{
				//komenda otwieraj¹ca opis
				gameStage = stage::opis;
				break;
			}
			if ((x == 5) && (event.key.code == Keyboard::Enter))
			{
				//komenda zamykaj¹ca gre
				window.close();
				break;
			}
		}
		break;
		}
		case stage::gra:
			if (SHp <= 0 )
			{
				gameStage = stage::KoniecGry;
				break;
			}
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == gra))
			{
				gameStage = stage::menu;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			if ((Keyboard::isKeyPressed(Keyboard::F1)) && (gameStage == gra))
			{
				gameStage = stage::opisWgrze;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			break;
		case stage::ZapiszGre:
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == ZapiszGre))
			{
				gameStage = stage::menu;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			break;
		case stage::WczytajGre:
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == WczytajGre))
			{
				gameStage = stage::menu;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			break;
		case stage::TrudnoscGry:
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == TrudnoscGry))
			{
				gameStage = stage::menu;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			break;
		case stage::opis:
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == opis))
			{
				gameStage = stage::menu;
				cout << "Gamestage =" << gameStage << " \n";
				break;
			}
			break;
		case stage::opisWgrze:
			if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == opisWgrze))
			{
				gameStage = stage::gra;
				cout << "Gamestage =" << gameStage << " \n";
				Sleep(150);
				break;
			}

	}
	}
}



// funkcja okreœlaj¹ca pojedyncze sekwencje zmiany pozycji menu,gry,opcji
void Game::updateEvent(Event& event, RenderWindow& window,MainMenu& mainMenu, Starship& starship, Zapiszgre& zapiszgre,  Wczytajgre& wczytajgre, Trudnosc& trudnosc,Pocisk& pocisk)
{	
	//Aktualne zdarzenia
	switch (gameStage)
	{
	case stage::menu:
		mainMenu.updateMenu(event,window);
		StageControl(event,window, mainMenu,starship);
		break;
	case stage::gra:
		StageControl(event,window, mainMenu,starship);
		if (event.key.code == Keyboard::Space)
		{
			pocisk.SummonPocisk(starship);
		}
		break;
	case stage::ZapiszGre:
		zapiszgre.uploadZapisz(event, window);
		StageControl(event, window, mainMenu, starship);
		break;
	case stage::WczytajGre:
		wczytajgre.uploadWczytaj(event, window);
		StageControl(event, window, mainMenu, starship);
		break;
	case stage::TrudnoscGry:
		StageControl(event, window, mainMenu, starship);
		trudnosc.uploadTrudnosc(event, window);
		break;
	case stage::opis:
		StageControl(event, window, mainMenu, starship);
		break;
	case stage::opisWgrze:
		StageControl(event, window, mainMenu, starship);
		break;
	case stage::KoniecGry:
		StageControl(event, window, mainMenu, starship);
		break;
	}
}// funkcje odpowiedzialne za poruszanie sie statkiem	
void Game::update(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy, Zapiszgre& zapiszgre,  Wczytajgre& wczytajgre, Trudnosc& trudnosc,Pocisk& pocisk)
{
	switch (gameStage)
	{
	case stage::menu:
		break;
	case stage::gra:
			SHp=MaxSHp - enemy.dmg;
		updateStatistic();
		pocisk.uploadPocisk();
		AsteroidMove();
		enemy.MovePosition();
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			starship.MoveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			starship.MoveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			starship.MoveLeft();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			starship.MoveRight();
		}
		break;
	case stage::ZapiszGre:
		break;
	case stage::WczytajGre:
		break;
	case stage::TrudnoscGry:
		if (trudnosc.WybranypoziomTrudnosci() == 3)
		{
			MaxSHp = 1001;
		}
		if (trudnosc.WybranypoziomTrudnosci() == 2)
		{
			MaxSHp = 701;
		}
		if (trudnosc.WybranypoziomTrudnosci() == 1)
		{
			MaxSHp = 301;
		}
		break;
	case stage::opis:
		break;
	case stage::opisWgrze:
		break;
	case stage::KoniecGry:
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			gameStage = stage::menu;
			SHp = 1001;
			MaxSHp = 1001;
			score = 0;
		}
		AsteroidMove();
		break;
	}
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy,Opis& opis, Zapiszgre& zapiszgre,  Wczytajgre& wczytajgre, Trudnosc& trudnosc, Pocisk& pocisk)
{
    window.clear(Color::Green);
  
	switch (gameStage)
	{
	case stage::menu:
		DrawBackground(window);
		mainMenu.draw(window);

		break;
	case stage::gra:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		pocisk.DrawPocisk(window);
		enemy.DrawEnemy(window,starship,1,pocisk);
		starship.Drawstarship(window);
		StatisticDraw(window);
		break;
	case stage::ZapiszGre:
		DrawBackground(window);
		zapiszgre.drawZapisz(window);
		break;
	case stage::WczytajGre:
		DrawBackground(window);
		wczytajgre.drawWczytaj(window);
		break;
	case stage::TrudnoscGry:
		DrawBackground(window);
		trudnosc.drawTrudnosc(window);
		break;
	case stage::opis:
		DrawBackground(window);
		opis.DrawOpis(window);
		break;
	case stage::opisWgrze:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		pocisk.DrawPocisk(window);
		StatisticDraw(window);
		enemy.DrawEnemy(window,starship,0,pocisk);
		starship.Drawstarship(window);
		opis.DrawOpis(window);
		break;
	case stage::KoniecGry:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		StatisticDraw(window);
		break;
	}

    window.display();
}


