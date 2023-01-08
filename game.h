#pragma once
#include "biblioteka.h"
#include "MainMenu.h"



class Game
{
private:
	Texture Maintexture;
	Sprite sprite;
	enum stage{menu,gra,koniecGry};
	int gameStage = 0;
	float scores;
public:
	
	Game();
	~Game();
	void DrawBackground(RenderWindow& window);
	void StageControl(Event& event, MainMenu& mainMenu);
	void StageUp();
	void StageDown();
	void render(RenderWindow& window, MainMenu& mainMenu);
	void update(Event& event, RenderWindow& window, MainMenu& mainMenu);
};