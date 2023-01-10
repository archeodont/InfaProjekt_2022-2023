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
    window.setFramerateLimit(30);
    
    //wywołanie wszystkich klas
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    Game game;
    Starship starship;
    Enemy enemy;
    Clock EnemyClock;

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
            game.updateEvent(event, window, mainMenu,starship);
        } 

        //funkcja odpowiedzialna za uaktualnianie statystyk w czasie rzeczywistym
        game.update(window,mainMenu,starship,enemy);

        //Funkcja odpowiedzialna za rysowanie okna
        game.render(window, mainMenu, starship,enemy);
    }
    return 0;
}