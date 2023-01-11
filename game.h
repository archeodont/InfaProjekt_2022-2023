#pragma once
#include "biblioteka.h"
#include "MainMenu.h"
#include "Starship.h"
#include "Enemy.h"


class Game
{
private:
	Sprite MenuSprite, GameSprite;
	Texture MenuTexture, GameTexture;
	enum stage{menu,gra,koniecGry};
	int gameStage = 0;
	int scores = 0;
	int a=0, b=0;
public:
	
	Game();
	~Game();
	void DrawBackground(RenderWindow& window);
	void DrawBackgroundGame(RenderWindow& window);
	void StageControl(Event& event, MainMenu& mainMenu, Starship& starship);
	void render(RenderWindow& window, MainMenu& mainMenu, Starship& starship,Enemy& enemy);
	void updateEvent(Event& event, RenderWindow& window, MainMenu& mainMenu,Starship& starship);
	void update(RenderWindow& window, MainMenu& mainMenu, Starship& starship,Enemy& enemy);
	
};