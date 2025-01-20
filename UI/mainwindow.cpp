#include "mainwindow.h"

MainWindow::MainWindow(UIBoard *UIboard, WinConstants &winConst)
    :m_UIboard(UIboard), m_winState{nullptr}
{
    m_windowSize = {winConst.WIDTH, winConst.HEIGHT};
    m_rendWindow.create(sf :: VideoMode(winConst.WIDTH, winConst.HEIGHT), winConst.TITLE, sf :: Style :: Titlebar | sf::Style::Close);
    m_rendWindow.setFramerateLimit(winConst.FRAMERATE);

    std :: shared_ptr<WinState> state = std :: make_shared<WinState>(WinState :: MAIN_MENU);
    m_winState = state.get();

    m_menu = std :: make_unique<Menu>(&m_rendWindow);
    m_menu->setState(state);
    m_endGame = std :: make_unique<EndGame>(&m_rendWindow, UIboard);
    m_endGame->setState(state);
    m_UIboard->setState(state);
    m_UIboard->setEndGameWindow(m_endGame.get());

    m_stateWindows[WinState :: MAIN_MENU]      = m_menu.get();
    m_stateWindows[WinState :: GAME]           = m_UIboard;
    m_stateWindows[WinState :: END_GAME]       = m_endGame.get();

}

MainWindow::~MainWindow()
{
    m_rendWindow.close();
}

void MainWindow::clear()
{
    m_rendWindow.clear();
}

void MainWindow::handleInput()
{
    sf :: Event event;
    while (m_rendWindow.pollEvent(event))
    {
        if (event.type == sf :: Event :: Closed)
        {
            m_rendWindow.close();
        }
        m_stateWindows[*m_winState]->handleInput(event);
    }
}

void MainWindow::display()
{
    m_rendWindow.display();
}

bool MainWindow::isOpen() const
{
    return m_rendWindow.isOpen();
}

void MainWindow::draw()
{
    m_rendWindow.draw(*m_stateWindows[*m_winState]);
}

const sf::Vector2u &MainWindow::getwindowSize() const
{
    return m_windowSize;
}
