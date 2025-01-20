#include "logic/game.h"

int main()
{

    Game game;

    while (game.isRunning())
    {
        game.handleInput();
        game.update();
        game.render();
    }

    return 0;
}
