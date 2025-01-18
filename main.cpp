#include "game.h"

int main()
{

    Game game;

    while (!game.isEnded())
    {
        game.handleInput();
        game.update();
        game.render();
    }

    return 0;
}
