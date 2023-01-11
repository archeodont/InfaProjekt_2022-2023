#pragma once
#include "biblioteka.h"
#include "MainMenu.h"
#include "Starship.h"
#include "Enemy.h"
#include "Opis.h"

// klasa wykorzystywana jako silnik gry, przyjmuje i przetwarza wiêkszoœæ danych
// Odpowiedzialna za renderowanie ekranu oraz uaktualnianie danych np pozycji
class Game
{
private:
	// zmienne odpowiadaj¹ce za obrazy
	Sprite MenuSprite, GameSprite, AsteroidSprite1, AsteroidSprite2, AsteroidSprite3, AsteroidSprite4, AsteroidSprite5;
	Texture MenuTexture, GameTexture, AsteroidTexture1, AsteroidTexture2, AsteroidTexture3, AsteroidTexture4, AsteroidTexture5;
	//zmienna stanu gry
	enum stage{menu,gra,ZapiszGre,WczytajGre,Ranking,opis,KoniecGry};
	int gameStage = 0;
	int scores = 0;
	
	//zmienne asteroid
	int Ax[20],Ay[20],Ady[20];

public:
	
	Game();
	~Game();
	void DrawBackground(RenderWindow& window);
	void DrawBackgroundGame(RenderWindow& window);
	void StageControl(Event& event,RenderWindow& window ,MainMenu& mainMenu, Starship& starship);
	void AsteroidMove();
	void AsteroidDraw(RenderWindow& window);
	void render(RenderWindow& window, MainMenu& mainMenu, Starship& starship,Enemy& enemy,Opis& opis);
	void updateEvent(Event& event, RenderWindow& window, MainMenu& mainMenu,Starship& starship);
	void update(RenderWindow& window, MainMenu& mainMenu, Starship& starship,Enemy& enemy);
	
};