#include "mainwindow.h"

MainWindow::MainWindow(UIBoard *UIboard, WinConstants &winConst)
    :m_UIboard(UIboard)
{
    m_windowSize = {winConst.WIDTH, winConst.HEIGHT};
    m_window.create(sf :: VideoMode(winConst.WIDTH, winConst.HEIGHT), winConst.TITLE, sf :: Style :: Titlebar | sf::Style::Close);
    m_window.setFramerateLimit(winConst.FRAMERATE);
}

void MainWindow::pollEvent(sf::Event &event)
{
    m_window.pollEvent(event);
}

MainWindow::~MainWindow()
{
    m_window.close();
}

void MainWindow::clear()
{
    m_window.clear();
}

void MainWindow::update()
{
    sf :: Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf :: Event :: Closed || (event.type == sf :: Event :: KeyPressed && event.key.code == sf :: Keyboard :: Escape))
        {
            m_window.close();
        }
        m_UIboard->handeInput(event);
    }
}

void MainWindow::display()
{
    m_window.display();
}

bool MainWindow::isOpen() const
{
    return m_window.isOpen();
}

void MainWindow::draw()
{
    m_window.draw(*m_UIboard);
}

const sf::Vector2u &MainWindow::getwindowSize() const
{
    return m_windowSize;
}
