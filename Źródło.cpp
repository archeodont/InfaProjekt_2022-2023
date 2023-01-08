#include "biblioteka.h"
#include "MainMenu.h"
#include "game.h"
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
    Game game;


    Texture Maintexture;
    Maintexture.loadFromFile("tlo.jpg");
    Sprite sprite(Maintexture);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }


            window.clear();
            mainMenu.updateMenu(event, window);
            //game.update(event, window);
            window.draw(sprite);
            mainMenu.draw(window);
            window.display();
        }


    }

    return 0;
}