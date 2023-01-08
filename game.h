#pragma once
#include "biblioteka.h"
#include "MainMenu.h"



class Game
{
private:
	enum stage{menu,gra,koniecGry};
	int gameStage = 0;
	float scores;
public:
	
	void update(Event& event, RenderWindow& window);
	void render(RenderWindow& window);
	void game();
};