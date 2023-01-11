#include "biblioteka.h"
#include "game.h"



//konstruktor
Game::Game()
{	//pobieranie t³a menu
	MenuTexture.loadFromFile("tlo.png");
	MenuSprite.setTexture(MenuTexture);
	MenuSprite.setScale(1.7,1);
	MenuSprite.setTextureRect(IntRect(0,150,1280,720));
	
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
						break;
					}
					if ((x == 2) && (event.key.code == Keyboard::Enter))
					{
						//komenda otwierajaca wczytanie gry
						break;
					}
					if ((x == 3) && (event.key.code == Keyboard::Enter))
					{
						//komenda otwierajaca Ranking
						break;
					}
					if ((x == 4) && (event.key.code == Keyboard::Enter))
					{
						//komenda otwierajaca opis
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
				if ((Keyboard::isKeyPressed(Keyboard::Escape)) && (gameStage == 1))
				{
					gameStage = stage::menu;
					cout << "Gamestage =" << gameStage << " \n";
				}
				break;

		}
	}
}



// funkcja okreœlaj¹ca pojedyncze sekwencje zmiany pozycji menu,gry,opcji
void Game::updateEvent(Event& event, RenderWindow& window,MainMenu& mainMenu, Starship& starship)
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
		break;
	case stage::KoniecGry:
		break;
	}
}// funkcje odpowiedzialne za poruszanie sie statkiem	
void Game::update(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy)
{	switch(gameStage)
	case stage::gra:
	{	
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
		
	}
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy)
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
		enemy.DrawEnemy(window);
		starship.Drawstarship(window);
		break;
	case stage::KoniecGry:

		break;
	}

    window.display();
}


