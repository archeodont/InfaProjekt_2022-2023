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
// rysowanie t³a w menu
void Game::DrawBackground(RenderWindow& window)
{
	Texture Maintexture;
	Maintexture.loadFromFile("tlo.jpg");
	Sprite sprite(Maintexture);
	window.draw(sprite);
}
//rysowanie t³a w grze
void Game::DrawBackgroundGame(RenderWindow& window)
{

}

// funkcjie odpowiedzialne za przemieszczanie siê pomiêdzy etapami gra,menu,koniec gry
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
							cout << "powrót do menu\n";
							gameStage = 0;
						}
						// funkcje odpowiedzialne za poruszanie sie statkiem	
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
						break;
					}
			}
	}
}

// funkcja okreœlaj¹ca co w danym czasie jest wykonywane
void Game::update(Event& event, RenderWindow& window,MainMenu& mainMenu, Starship& starship)
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
    
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window, MainMenu& mainMenu, Starship& starship)
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

		break;
	case koniecGry:

		break;
	}

    window.display();
}


