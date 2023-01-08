#include "biblioteka.h"
#include "game.h"
#include "MainMenu.h"	

using namespace Menu;

// funkcja okreœlaj¹ca co w danym czasie jest wykonywane
void Game::update(Event& event, RenderWindow& window)
{	
	//deklaracja innych klas
	for (int i = 0; i < 1; i++)
	{
		MainMenu Mmenu(window.getSize().x, window.getSize().y);
	}

	//Aktualne zdarzenia
	switch (gameStage)
	{
	case menu:
		Mmenu.updateMenu(event,window);
		break;
	case gra:
		break;
	case koniecGry:
		break;
	}
    
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
void Game::render(RenderWindow& window)
{
    window.clear();
  

    window.display();
}

void Game::game()
{

}