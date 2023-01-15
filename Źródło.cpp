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
    // inicjowanie liczb pseudolosowych
    srand(time(NULL));

    //Stworzenie okna gry
    RenderWindow window(VideoMode(width, height), " --- TYRIAN 2000 ---");
    window.setFramerateLimit(45);
    
    //wywołanie wszystkich klas
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    Game game;
    Starship starship;
    Enemy enemy(10);
    Opis opis;
    Zapiszgre zapiszgre;
    Wczytajgre wczytajGre;
    Trudnosc trudnosc;
    Pocisk pocisk(20);
  
    //Pętla gry
    while (window.isOpen())
    {
        //Time elapsed1 = EnemyClock.getElapsedTime();
        //  if (elapsed1.asSeconds() >= 20)
      
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            // Funkcja odpowiedzialna za obliczenia oraz obsluge
            game.updateEvent(event, window, mainMenu,starship,zapiszgre,wczytajGre,trudnosc,pocisk);
        } 

        //funkcja odpowiedzialna za uaktualnianie statystyk w czasie rzeczywistym
        game.update(window,mainMenu,starship,enemy,zapiszgre,wczytajGre,trudnosc,pocisk);

        //Funkcja odpowiedzialna za rysowanie okna
        game.render(window, mainMenu, starship,enemy,opis,zapiszgre,wczytajGre,trudnosc,pocisk);
    }
    return 0;
} 