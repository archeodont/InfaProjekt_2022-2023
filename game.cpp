#include "biblioteka.h"
#include "game.h"
#include "windows.h" 


//konstruktor
Game::Game(Starship& starship)
{	//Tworzenie zmiennych statystyk
	if (!font.loadFromFile("czcionka.ttf"))
	{
		cout << "Nie wykryto pliku arial";
	}

	//tekst statystyk ilosci HP
	StarshipHealth.setFont(font);
	StarshipHealth.setFillColor(Color::White);
	StarshipHealth.setString("Zycie: " + to_string(starship.SHp));
	StarshipHealth.setCharacterSize(30);
	StarshipHealth.setPosition(1270 - StarshipHealth.getLocalBounds().width-20, 1);

	//tekst statystyk ilo�ci punkt�w
	TimeInGame.setFont(font);
	TimeInGame.setFillColor(Color::White);
	TimeInGame.setString("Czas: "+ to_string(starship.score));
	TimeInGame.setCharacterSize(30);
	TimeInGame.setPosition(1270 - TimeInGame.getLocalBounds().width-64, 31);

	//tekst Konca gry
	EndGame[0].setFont(font);
	EndGame[0].setFillColor(Color::White);
	EndGame[0].setString("PRZEGRANA!");
	EndGame[0].setCharacterSize(200);
	EndGame[0].setPosition(640 - EndGame[0].getLocalBounds().width/2, 200);
	
	//tekst pod konce Gry
	EndGame[1].setFont(font);
	EndGame[1].setFillColor(Color::White);
	EndGame[1].setString("Kliknij ENTER by wyjsc");
	EndGame[1].setCharacterSize(50);
	EndGame[1].setPosition(640 - EndGame[1].getLocalBounds().width/2 , 450);

	//tekst wygranej
	Victory[0].setFont(font);
	Victory[0].setFillColor(Color::White);
	Victory[0].setString("WYGRANA!");
	Victory[0].setCharacterSize(200);
	Victory[0].setPosition(640 - Victory[0].getLocalBounds().width/2, 200);

	//podtekst wygranej
	Victory[1].setFont(font);
	Victory[1].setFillColor(Color::White);
	Victory[1].setString("Kliknij ENTER by wyjsc");
	Victory[1].setCharacterSize(50);
	Victory[1].setPosition(640 - Victory[1].getLocalBounds().width/2, 450);

	//pobieranie t�a menu
	MenuTexture.loadFromFile("tlo.png");
	MenuSprite.setTexture(MenuTexture);
	MenuSprite.setScale(1.7,1);
	MenuSprite.setTextureRect(IntRect(0,280,1280,720));
	
	//pobieranie t�a w grze
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

	//ustawianie pozycji pocz�tkowej asteroid
	for (int i = 0; i < 20; i++)
	{
		Ax[i] = rand() % 1200;
		Ay[i] = -rand() % 400;
		Ady[i] = rand() % 10+1;
	}
}

//destruktor
Game::~Game()
{

}

//Funkcja Ustalania po�o�enia asteroid
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



// funkcja aktualizuj�ca statystyki
void Game::updateStatistic(Starship& starship)
{
	StarshipHealth.setString("Health: " + to_string(starship.SHp));
	TimeInGame.setString("Score: " + to_string(starship.score));
}

// funkcja rysuj�ca statystyki
void Game::StatisticDraw(RenderWindow& window)
{
	window.draw(StarshipHealth);
	window.draw(TimeInGame);
}

// rysowanie t�a w menu
void Game::DrawBackground(RenderWindow& window)
{
	window.draw(MenuSprite);
}
//rysowanie t�a w grze
void Game::DrawBackgroundGame(RenderWindow& window)
{	
	window.draw(GameSprite);
}

// funkcjie odpowiedzialne za przemieszczanie si� pomi�dzy etapami gra,menu,koniec gry
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
				//komenda rozpoczynaj�ca gre
				gameStage = stage::gra;
				break;
			}
			if ((x == 1) && (event.key.code == Keyboard::Enter))
			{
				//komenda otwieraj�ca zapis gry
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
				//komenda otwieraj�ca opis
				gameStage = stage::opis;
				break;
			}
			if ((x == 5) && (event.key.code == Keyboard::Enter))
			{
				//komenda zamykaj�ca gre
				window.close();
				break;
			}
		}
		break;
		}
		case stage::gra:
			if (starship.SHp <= 0 )
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



// funkcja okre�laj�ca pojedyncze sekwencje zmiany pozycji menu,gry,opcji
void Game::updateEvent(Event& event, RenderWindow& window,MainMenu& mainMenu, Starship& starship, Zapiszgre& zapiszgre,  Wczytajgre& wczytajgre, Trudnosc& trudnosc,Pocisk& pocisk,Enemy& enemy)
{	
	int XXx = wczytajgre.WczytajPressed();
	int XxX = zapiszgre.ZapisPressed();
	float xyz = zapiszgre.ClockTime();
	//Aktualne zdarzenia
	switch (gameStage)
	{
	case stage::menu:
		mainMenu.updateMenu(event,window);
		StageControl(event,window, mainMenu,starship);
		zapiszgre.clockZapis.restart();
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

		if(xyz > 500)
		{
			zapiszgre.ClockRestart();
			if((event.key.code == Keyboard::Enter) && (XxX == 0))
			{
				printf(" zapis 1\n");
				zapiszgre.DownloadDataToSave(enemy.E1Hp, starship.SHp, starship.score, "data1.txt");
			}
			if ((event.key.code == Keyboard::Enter) && (XxX == 1))
			{
				printf(" zapis 2\n");
				zapiszgre.DownloadDataToSave(enemy.E1Hp, starship.SHp, starship.score, "data2.txt");

			}
			if ((event.key.code == Keyboard::Enter) && (XxX == 2))
			{
				printf(" zapis 3\n");
				zapiszgre.DownloadDataToSave(enemy.E1Hp, starship.SHp, starship.score, "data3.txt");

			}
			if ((event.key.code == Keyboard::Enter) && (XxX == 3))
			{
				printf(" zapis 4\n");
				zapiszgre.DownloadDataToSave(enemy.E1Hp, starship.SHp, starship.score, "data4.txt");

			}
		}
		break;
	case stage::WczytajGre:
		wczytajgre.uploadWczytaj(event, window);
		StageControl(event, window, mainMenu, starship);

		if (xyz > 500)
		{
			zapiszgre.ClockRestart();
			if ((event.key.code == Keyboard::Enter) && (XXx == 0))
			{
				printf("Wczytano zapis 1\n");
				wczytajgre.DownloadDataToGame( "data1.txt",starship,enemy);
			}
			if ((event.key.code == Keyboard::Enter) && (XXx == 1))
			{
				printf("Wczytano zapis 2\n");
				wczytajgre.DownloadDataToGame("data2.txt", starship, enemy);

			}
			if ((event.key.code == Keyboard::Enter) && (XXx == 2))
			{
				printf("Wczytano zapis 3\n");
				wczytajgre.DownloadDataToGame("data3.txt", starship, enemy);

			}
			if ((event.key.code == Keyboard::Enter) && (XXx == 3))
			{
				printf("Wczytano zapis 4\n");
				wczytajgre.DownloadDataToGame("data4.txt", starship, enemy);

			}
		}

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
			starship.SHp=starship.MaxSHp - enemy.dmg;	
			starship.score = enemy.DMGdealtToEnemy();
		updateStatistic(starship);
		pocisk.uploadPocisk();
		if (enemy.ZeroEnemy() == 0)
			gameStage = stage::Wygrana;
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
			starship.MaxSHp = 1001;
		}
		if (trudnosc.WybranypoziomTrudnosci() == 2)
		{
			starship.MaxSHp = 701;
		}
		if (trudnosc.WybranypoziomTrudnosci() == 1)
		{
			starship.MaxSHp = 301;
		}
		break;
	case stage::opis:
		color = Color(120, 80, 0);
		break;
	case stage::opisWgrze:
		color = Color::White;
		break;
	case stage::KoniecGry:
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			window.close();
		}
		AsteroidMove();
		break;
	case stage::Wygrana:
		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			window.close();
		}
		AsteroidMove();
		break;
	}

}


//funkcja okre�laj�ca co w danym czasie jest renderowane
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
		opis.DrawOpis(window,color,0);
		break;
	case stage::opisWgrze:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		pocisk.DrawPocisk(window);
		StatisticDraw(window);
		enemy.DrawEnemy(window,starship,0,pocisk);
		starship.Drawstarship(window);
		opis.DrawOpis(window,color,1);
		break;
	case stage::KoniecGry:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		window.draw(EndGame[0]);
		window.draw(EndGame[1]);
		StatisticDraw(window);
		break;
	case stage::Wygrana:
		DrawBackgroundGame(window);
		AsteroidDraw(window);
		window.draw(Victory[0]);
		window.draw(Victory[1]);
		StatisticDraw(window);
	}

    window.display();
}


