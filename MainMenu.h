#pragma once
#include "biblioteka.h"

#define Max_main_menu 4

class MainMenu
{
public:

	MainMenu(float width,float hight);

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void update(Event& event, RenderWindow& window);

	int MainMenuPressed() { return MainMenuSelected;
}
	~MainMenu();
	
	
private:
	int CurrentlySelected = 0;
	int MainMenuSelected = 0;
	Font font;
	Text mainMenu[Max_main_menu];
	Event ev;
};

