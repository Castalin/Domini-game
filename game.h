#ifndef GAME_H
#define GAME_H

#include "UI/mainwindow.h"
#include "UI/board.h"
#include "logicboard.h"

class Game
{
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();

    bool isEnded();

private:
    MainWindow m_window;
    std :: unique_ptr<Board> m_UIboard;
    std :: unique_ptr<LogicBoard> m_logicBord;
};

#endif // GAME_H
