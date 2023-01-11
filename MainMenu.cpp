#include "MainMenu.h"
int menuwidth = 640;
int menuheight = 250;
int hdiff = 70;

//konstruktor
MainMenu::MainMenu(float width, float hight)
{
	if (!font.loadFromFile("czcionka.ttf"))
		cout << "Nie wykryto pliku arial";

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Color(255, 215, 0));
	mainMenu[0].setString("Graj");
	mainMenu[0].setCharacterSize(60);
	mainMenu[0].setPosition(menuwidth - mainMenu[0].getLocalBounds().width / 2.f, menuheight);
	

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Color(120, 80, 0));
	mainMenu[1].setString("Zapisz gre");
	mainMenu[1].setCharacterSize(60);
	mainMenu[1].setPosition(menuwidth - mainMenu[1].getLocalBounds().width / 2.f, menuheight + hdiff);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Color(120, 80, 0));
	mainMenu[2].setString("Wczytaj gre");
	mainMenu[2].setCharacterSize(60);
	mainMenu[2].setPosition(menuwidth - mainMenu[2].getLocalBounds().width / 2.f, menuheight + hdiff * 2);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::Color(120, 80, 0));
	mainMenu[3].setString("Ranking");
	mainMenu[3].setCharacterSize(60);
	mainMenu[3].setPosition(menuwidth - mainMenu[3].getLocalBounds().width / 2.f, menuheight + hdiff * 3);

	mainMenu[4].setFont(font);
	mainMenu[4].setFillColor(Color::Color(120, 80, 0));
	mainMenu[4].setString("Opis");
	mainMenu[4].setCharacterSize(60);
	mainMenu[4].setPosition(menuwidth - mainMenu[4].getLocalBounds().width / 2.f, menuheight + hdiff * 4);

	mainMenu[5].setFont(font);
	mainMenu[5].setFillColor(Color::Color(120, 80, 0));
	mainMenu[5].setString("Wyjdz z Gry");
	mainMenu[5].setCharacterSize(60);
	mainMenu[5].setPosition(menuwidth - mainMenu[5].getLocalBounds().width / 2.f, menuheight + hdiff * 5);

	MainMenuSelected = 0;


	
}

//destruktor
MainMenu::~MainMenu()
{

}


// Funkcja draw
void MainMenu::draw(RenderWindow& window) {
	
	for (int i = 0; i < Max_main_menu; i++) {
		window.draw(mainMenu[i]);
	}
	
}

//funkcja MuveUp
void MainMenu::MoveUp()
{
	if (MainMenuSelected >= 0 && MainMenuSelected <= 5) {
		mainMenu[CurrentlySelected].setFillColor(Color::Color(120, 80, 0));

		MainMenuSelected--;
		if (MainMenuSelected < 0) {
			MainMenuSelected = 5;
		}
		CurrentlySelected = MainMenuSelected;  
		mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 215, 0));
	}
}

//funkcja MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected >= 0 && MainMenuSelected <= 5) {
		mainMenu[CurrentlySelected].setFillColor(Color::Color(120, 80, 0));

		MainMenuSelected++;
		if (MainMenuSelected == 6) {
			MainMenuSelected = 0;
		}
		CurrentlySelected = MainMenuSelected;
		mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 215, 0));
	}
}



//funkcja update
void MainMenu::updateMenu(Event& event, RenderWindow& window)
{
	
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Up)
			{
				MoveUp();
				break;
			}
			if (event.key.code == Keyboard::Down)
			{
				MoveDown();
				break;
			}
		case Keyboard::Enter:
			if (MainMenuSelected == 0)
			{
				printf("wybrano nowa gra\n");
				break;
			} 
			if (MainMenuSelected == 1)
			{
		 		printf("wybrano zapisz gre\n");
				break;
			}
			if (MainMenuSelected == 2)
			{
				printf("wybrano wczytaj gre\n");
				break;
			}
			if (MainMenuSelected == 3)
			{
				printf("wybrano Ranking\n");
				break;
			}
			if (MainMenuSelected == 4)
			{
				printf("wybrano Opis\n");
				break;
			}
			if (MainMenuSelected == 5)
			{
				printf("wybrano wyjdz z gry\n");
				break;
			}
		}

	
   

}

