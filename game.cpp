#include "game.h"

Game :: Game()
{
    BoardConstants boardConst;
    m_logicBord = std :: make_unique<LogicBoard>(boardConst);

    m_UIboard = std :: make_unique<Board>(&m_window, boardConst);
    m_UIboard->setFigures(m_logicBord->getfigures());
}

Game::~Game()
{

}

void Game :: handleInput()
{

}

void Game :: update()
{
    m_window.update();
}

void Game :: render()
{
    m_window.clear();
    m_UIboard->draw();
    m_window.display();
}

bool Game :: isEnded()
{
    return !m_window.isOpen();
}
