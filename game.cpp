#include "game.h"

Game :: Game()
{
    m_logicBoard = std :: make_unique<LogicBoard>();
    WinConstants winConst;
    m_UIboard = std :: make_unique<UIBoard>(m_logicBoard.get(), winConst);
    m_window = std :: make_unique<MainWindow>(m_UIboard.get(), winConst);
}

Game::~Game()
{

}

void Game :: handleInput()
{

}

void Game :: update()
{
    m_window->update();
    m_logicBoard->checkWinner();
}

void Game :: render()
{
    m_window->clear();
    m_window->draw();
    m_window->display();
}

bool Game :: isRunning()
{
    return m_window->isOpen();
}
