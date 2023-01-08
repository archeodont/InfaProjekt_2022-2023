#include "biblioteka.h"
#include "game.h"
#include "MainMenu.h"	




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
// funkcjie odpowiedzialne za przemieszczanie siê pomiêdzy etapami gra,menu,koniec gry

void Game::StageControl(Event& event, MainMenu& mainMenu)
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
						gameStage++;
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
							gameStage--;
							break;
						}
					}
			}
	}
}

// funkcja okreœlaj¹ca co w danym czasie jest wykonywane
void Game::update(Event& event, RenderWindow& window,MainMenu& mainMenu)
{	
	

	//Aktualne zdarzenia
	switch (gameStage)
	{
	case menu:
		mainMenu.updateMenu(event,window);
		StageControl(event, mainMenu);
		break;
	case gra:
		StageControl(event, mainMenu);
		break;
	case koniecGry:
		break;
	}
    
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window, MainMenu& mainMenu)
{
    window.clear();
  
	switch (gameStage)
	{
	case menu:
		DrawBackground(window);
		mainMenu.draw(window);

		break;
	case gra:

		break;
	case koniecGry:

		break;
	}

    window.display();
}


