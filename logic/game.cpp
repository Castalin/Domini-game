#include "game.h"

Game :: Game()
{
    m_logicBoard = std :: make_unique<LogicBoard>();
    WinConstants winConst;
    m_UIboard = std :: make_unique<UIBoard>(m_logicBoard.get(), winConst);
    m_window = std :: make_unique<MainWindow>(m_UIboard.get(), winConst);
    m_basicAI = std :: make_unique<AI>(m_logicBoard->getgameBoard(), m_UIboard->getPlayerFigure(Player :: PLAYER_2), Player :: PLAYER_2);
}

Game::~Game()
{

}

void Game :: handleInput()
{
    m_window->handleInput();
}

void Game :: update()
{
    if (m_basicAI->getplayerType() == m_logicBoard->getTurn())
    {
        m_basicAI->findOptimal();
        m_UIboard->selectFigure(m_basicAI->getoptimalFig());
        m_UIboard->tryToMoveFigure(m_basicAI->getoptimalCell());
        m_UIboard->checkGameState();
    }
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
