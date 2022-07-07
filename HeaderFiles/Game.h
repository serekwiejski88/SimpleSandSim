#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include <vector>
#include "Map.h"
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Game
{
    public:
        // Konstruktory i destruktory
        Game();
        virtual ~Game();
        
        // Funkcje publiczne
        void update();
        void render();

        //Gettery i settery
        const bool getWindowIsOpen() const;

      
    protected:
    
    private:
        //Obiekt mapy cząsteczek
        Map mapka;
      
        // Okienko aplikacji
        sf::RenderWindow* window;
        sf::Event event;
        sf::VideoMode videoMode;
        
        //Lokalizacja myszy
        sf::Vector2i mousePos;
        
        // Funkcje prywatne
        void updateObjects();
        void updateMousePos();
        void initializeWindow();
        void pollEvents();
        
};

#endif 