#include "biblioteka.h"
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
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }


            if (event.type == Event::KeyPressed)
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
                    RenderWindow Gra(VideoMode(960, 720), "Tyrian 2000");
                    RenderWindow Zapis(VideoMode(960, 720), "Zapisz gre");
                    RenderWindow Wczytaj(VideoMode(960, 720), "Wczytaj gre");

                    int x = mainMenu.MainMenuPressed();
                    if (x == 0)
                    {
                        while (Gra.isOpen())
                        {
                            Event aevent;
                            while (Gra.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Gra.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Gra.close();
                                    }
                                }
                            }
                            Zapis.close();
                            Wczytaj.close();
                            Gra.clear();
                            Gra.display();
                        }   
                    }
                    if (x == 1)
                    {
                        while (Zapis.isOpen())
                        {
                            Event aevent;
                            while (Zapis.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Zapis.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Zapis.close();
                                    }
                                }
                            }
                            Gra.close();
                            Zapis.clear();
                            Wczytaj.close();
                            Zapis.display();
                        }
                    }
                    if (x == 2)
                    {
                        while (Wczytaj.isOpen())
                        {
                            Event aevent;
                            while (Wczytaj.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed)
                                {
                                    Wczytaj.close();
                                }
                                if (aevent.type == Event::KeyPressed)
                                {
                                    if (aevent.key.code == Keyboard::Escape)
                                    {
                                        Wczytaj.close();
                                    }
                                }
                            }
                            Gra.close();
                            Zapis.close();
                            Wczytaj.clear();
                            Wczytaj.display();
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
            window.draw(sprite);
            mainMenu.draw(window);
            window.display();
        }

       
    }

    return 0;
}
   