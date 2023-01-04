#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MainMenu.h"

// Gra bêdzie w stylu Space Invaders, tworz¹c program inspirujê siê Tyrian 2000
// G³ównym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwiêkszej iloœci wrogów


const int width = 1920;
const int height = 1080;
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(width, height), "TYRIAN 2000");
    MainMenu mainMenu(window.getSize().x, window.getSize.y());


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();

            }


            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }

                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }

                if (event.key.code == Keyboard::Return)
                {
                    RenderWindow Play(VideoMode(960, 720), "game_name");
                    RenderWindow OPTIONS(VideoMode(960, 720), "game_name");
                    RenderWindow ABOUT(VideoMode(960, 720), "game_name");

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)
                    {
                        while()
                    }
                }

            }


        }

        window.clear();
        //rysowanie gry
        window.display();
    }

    return 0;
}
   