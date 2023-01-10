#include "biblioteka.h"
#include "game.h"

// Gra bêdzie w stylu Space Invaders, tworz¹c program inspirujê siê Tyrian 2000
// G³ównym celem jest przetrwanie naszego statku kosmicznego i zniszczenie jak najwiêkszej iloœci wrogów

const int width = 1280;
const int height = 720;
using namespace sf;
using namespace std;

//pętla główna
int main()
{   
    //Stworzenie okna gry
    RenderWindow window(VideoMode(width, height), " --- TYRIAN 2000 ---");
    window.setFramerateLimit(60);
    
    //wywołanie wszystkich klas
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    Game game;
    Starship starship;

    //Pętla gry
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            // Funkcja odpowiedzialna za obliczenia oraz obsluge
            game.update(event, window, mainMenu,starship);
         
            //Funkcja odpowiedzialna za rysowanie okna
            game.render(window,mainMenu,starship);
        }
      

    }
    return 0;
}