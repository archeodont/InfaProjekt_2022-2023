#include "MainMenu.h"
int menuwidth = 110;
int menuheight = 350;
int hdiff = 70;

//konstruktor
MainMenu::MainMenu(float width, float hight)
{
	if (!font.loadFromFile("Arial.ttf"))
		cout << "Nie wykryto pliku arial";

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Color(255, 69, 0));
	mainMenu[0].setString("Nowa Gra");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(menuwidth, menuheight);

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Ranking");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(menuwidth , menuheight + hdiff);

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Opis");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(menuwidth , menuheight+2*hdiff);

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Wyjdz z Gry");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(menuwidth, menuheight+3*hdiff);

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
	if (MainMenuSelected >= 0 && MainMenuSelected <= 3) {
		mainMenu[CurrentlySelected].setFillColor(Color::White);  

		MainMenuSelected--;
		if (MainMenuSelected < 0) {
			MainMenuSelected = 3;
		}
		CurrentlySelected = MainMenuSelected;  
		mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 69, 0));
	}
}

//funkcja MoveDown
void MainMenu::MoveDown()
{
	if (MainMenuSelected >= 0 && MainMenuSelected <= 3) {
		mainMenu[CurrentlySelected].setFillColor(Color::White);

		MainMenuSelected++;
		if (MainMenuSelected == 4) {
			MainMenuSelected = 0;
		}
		CurrentlySelected = MainMenuSelected;
		mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 69, 0));
	}
}


//funkcja update
void MainMenu::update(Event& event, RenderWindow& window)
{
	
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Up)
			{
				if (MainMenuSelected >= 0 && MainMenuSelected <= 3) {
					mainMenu[CurrentlySelected].setFillColor(Color::White);

					MainMenuSelected--;
					if (MainMenuSelected < 0) {
						MainMenuSelected = 3;
					}
					CurrentlySelected = MainMenuSelected;
					mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 69, 0));
				}
				break;
			}
			if (event.key.code == Keyboard::Down)
			{
				if (MainMenuSelected >= 0 && MainMenuSelected <= 3) {
					mainMenu[CurrentlySelected].setFillColor(Color::White);

					MainMenuSelected++;
					if (MainMenuSelected == 4) {
						MainMenuSelected = 0;
					}
					CurrentlySelected = MainMenuSelected;
					mainMenu[CurrentlySelected].setFillColor(Color::Color(255, 69, 0));
				}
				break;
			}
		case Keyboard::Return:
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
				printf("wybrano wyjdz z gry\n");
				window.close();
				break;
			}

		}

	
   

}