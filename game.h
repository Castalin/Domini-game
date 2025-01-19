#ifndef GAME_H
#define GAME_H

#include "UI/mainwindow.h"
#include "UI/UIboard.h"
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
    std :: unique_ptr<MainWindow> m_window;
    std :: unique_ptr<UIBoard> m_UIboard;
    std :: unique_ptr<LogicBoard> m_logicBoard;
};

#endif // GAME_H
