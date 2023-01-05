#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MainMenu.h"

// Gra bêdzie w stylu Space Invaders, tworz¹c program inspirujê siê Tyrian 2000
// G³ównym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwiêkszej iloœci wrogów


const int width = 960;
const int height = 720;
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(width, height), "TYRIAN 2000");
    MainMenu mainMenu(window.getSize().x, window.getSize().y);

    RectangleShape background;
    Texture Maintexture;
    Maintexture.loadFromFile("background.jpg");
    background.setTexture(&Maintexture);

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
                        while (Play.isOpen())
                        {
                            Event aevent;
                            while (Play.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Play.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Play.close();
                                    }
                                }
                            }
                            OPTIONS.close();
                            ABOUT.close();
                            Play.clear();
                            Play.display();
                        }   
                    }
                    if (x == 1)
                    {
                        while (OPTIONS.isOpen())
                        {
                            Event aevent;
                            while (OPTIONS.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    OPTIONS.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        OPTIONS.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.clear();
                            ABOUT.close();
                            OPTIONS.display();
                        }
                    }
                    if (x == 2)
                    {
                        while (ABOUT.isOpen())
                        {
                            Event aevent;
                            while (ABOUT.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    ABOUT.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        ABOUT.close();
                                    }
                                }
                            }
                            Play.close();
                            OPTIONS.close();
                            ABOUT.clear();
                            ABOUT.display();
                        }
                    }
                    if (x == 3)
                    {
                        window.close();
                        break;

                    }
                }

            }

            window.clear();
            window.draw(background);
            mainMenu.draw(window);
            window.display();
        }

       
    }

    return 0;
}
   