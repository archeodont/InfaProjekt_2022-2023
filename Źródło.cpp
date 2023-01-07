#include "Game.h"
// Gra bêdzie w stylu Space Invaders, tworz¹c program inspirujê siê Tyrian 2000
// G³ównym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwiêkszej iloœci wrogów

const int width = 1280;
const int height = 720;
using namespace sf;
using namespace std;



int main()
{
    RenderWindow window(VideoMode(width, height), "MENU - TYRIAN 2000");
    MainMenu mainMenu(window.getSize().x, window.getSize().y);


    sf::Texture Maintexture;
    Maintexture.loadFromFile("tlo.jpg");
    Sprite sprite(Maintexture);

   

    while (window.isOpen())
    {
        Event ev;
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (ev.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if (ev.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
            case Keyboard::Return:
                if (mainMenu.MainMenuPressed() == 0)
                {
                    printf("wybrano nowa gra\n");
                    break;
                }
                if (mainMenu.MainMenuPressed() == 1)
                {
                    printf("wybrano zapisz gre\n");
                    break;
                }
                if (mainMenu.MainMenuPressed() == 2)
                {
                    printf("wybrano wczytaj gre\n");
                    break;
                }
                if (mainMenu.MainMenuPressed() == 3)
                {
                    printf("wybrano wyjdz z gry\n");
                    window.close();
                    break;
                }

            }
         
        }

        window.clear();
        window.draw(sprite);
        mainMenu.draw(window);
        window.display();
    }

    return 0;
}