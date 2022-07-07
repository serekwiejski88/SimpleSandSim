#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "Game.h"

int main()
{
    // Init game engine
    Game game;

    while (game.getWindowIsOpen())
    {
        game.update();
        game.render();
    }

    return 0;
}

