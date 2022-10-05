#include "Game.h"
#include <iostream>

int main()
{
    // Init Game engine
    Game game;

    // Game loop
    while (game.running())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
    return 0;
}


