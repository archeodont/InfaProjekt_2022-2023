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
	Texture MenuTexture;
	MenuTexture.loadFromFile("tlo.jpg");
	Sprite MenuSprite(MenuTexture);
	window.draw(MenuSprite);
}
//rysowanie t³a w grze
void Game::DrawBackgroundGame(RenderWindow& window)
{	
		Texture GameTexture;
		GameTexture.loadFromFile("tlogra.png");
		Sprite GameSprite(GameTexture);
		GameSprite.setScale(1.3, 1.3);
		window.draw(GameSprite);
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
				if ((x == 1) && (event.key.code == Keyboard::Enter))
				{
					//komenda otwieraj¹ca ranking
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
					cout << "powrot do menu\n";
					gameStage = 0;
				}
				break;
			}
		}
	}
	}
}

// funkcja okreœlaj¹ca pojedyncze sekwencje zmiany pozycji menu,gry,opcji
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
		if (gameStage == gra)
		{
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
}

//funkcja okreœlaj¹ca co w danym czasie jest renderowane
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
		DrawBackgroundGame(window);
		enemy.DrawEnemy(window);
		starship.Drawstarship(window);
		

		break;
	case koniecGry:

		break;
	}

    window.display();
}


