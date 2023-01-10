#include "biblioteka.h"
#include "game.h"



//konstruktor
Game::Game()
{
	
}

//destruktor
Game::~Game()
{

}
// rysowanie t�a w menu
void Game::DrawBackground(RenderWindow& window)
{
	Texture Maintexture;
	Maintexture.loadFromFile("tlo.jpg");
	Sprite sprite(Maintexture);
	window.draw(sprite);
}
//rysowanie t�a w grze
void Game::DrawBackgroundGame(RenderWindow& window)
{

}

// funkcjie odpowiedzialne za przemieszczanie si� pomi�dzy etapami gra,menu,koniec gry
void Game::StageControl(Event& event, MainMenu& mainMenu,Starship& starship)
{
	int x = mainMenu.MainMenuPressed();
	switch (gameStage)
	{
	case menu:
	{
		switch (event.type)
		{
			case Event::KeyPressed:
			{
				if ((x == 0) && (event.key.code == Keyboard::Enter))
				{
					gameStage = 1;
					break;
				}
				if ((x == 1) && (event.key.code == Keyboard::Enter))
				{
					//komenda otwieraj�ca ranking
					break;
				}
				if ((x == 2) && (event.key.code == Keyboard::Enter))
				{
					//komenda otwierajaca opis
					break;
				}
			}
		break;
		}
	case gra:
		switch (event.type)
		{
			case Event::KeyPressed:
			{
				if (event.key.code == Keyboard::Escape)
				{
					cout << "powr�t do menu\n";
					gameStage = 0;
				}


				break;
			}
		}
	}
	}
}

// funkcja okre�laj�ca pojedyncze sekwencje zmiany pozycji menu,gry,opcji
void Game::updateEvent(Event& event, RenderWindow& window,MainMenu& mainMenu, Starship& starship)
{	
	//Aktualne zdarzenia
	switch (gameStage)
	{
	case menu:
		mainMenu.updateMenu(event,window);
		StageControl(event, mainMenu,starship);
		break;
	case gra:
		StageControl(event, mainMenu,starship);
		break;
	case koniecGry:
		break;
	}
}// funkcje odpowiedzialne za poruszanie sie statkiem	
void Game::update(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy)
{	switch(gameStage)
	case gra:
	{	
		enemy.MovePosition();
		enemy.xClock();
		if (gameStage == gra)
		{
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				starship.MoveUp();
				cout << "Gora\n";
			}

			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				starship.MoveDown();
				cout << "Dol\n";
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				starship.MoveLeft();
				cout << "Lewo\n";
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				starship.MoveRight();
				cout << "Prawo\n";
			}
		}
	}
}

//funkcja okre�laj�ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window, MainMenu& mainMenu, Starship& starship, Enemy& enemy)
{
    window.clear(Color::Blue);
  
	switch (gameStage)
	{
	case menu:
		DrawBackground(window);
		mainMenu.draw(window);

		break;
	case gra:
		starship.Drawstarship(window);
		enemy.DrawEnemy(window);

		break;
	case koniecGry:

		break;
	}

    window.display();
}


