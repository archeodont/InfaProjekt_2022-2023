#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Gra bêdzie w stylu Space Invaders, tworz¹c program inspirujê siê Tyrian 2000
// G³ównym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwiêkszej iloœæi wrogów

int displayMenu;
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

class 


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TYRIAN 2000");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
    }

    return 0;
}
   