#include "MainMenu.h"

MainMenu::MainMenu(float width, float height)
{
	if (!font.loadFromFile("Arial.ttf"))
		cout << "Nie wykryto pliku arial";

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Nowa Gra");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Zapisz Grê");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 400);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Wczytaj Grê");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 600);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Wyjdz z Gry");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(400, 800);

	MainMenuSelected = -1;
}


MainMenu::~MainMenu()
{

}


// Funkcja draw
void MainMenu::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
}


// Funkcja MoveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected - 1 >= 0) {
		mainMenu[MainMenuSelected].setFillColor(Color::White);

		MainMenuSelected--;
		if (MainMenuSelected == -1) {
			MainMenuSelected = 3;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}
}


//Funkcja MoveDown
void MainMenu::MoveDown() {
	if (MainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[MainMenuSelected].setFillColor(Color::White);
		MainMenuSelected++;
		if (MainMenuSelected == 4)
		{
			MainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setFillColor(Color::Blue);
	}

}