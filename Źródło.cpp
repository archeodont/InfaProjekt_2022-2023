#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Gra b�dzie w stylu Space Invaders, tworz�c program inspiruj� si� Tyrian 2000
// G��wnym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwi�kszej ilo�ci wrog�w


const int width = 1920;
const int height = 1080;



int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "TYRIAN 2000");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        //rysowanie gry
        window.display();
    }

    return 0;
}
   