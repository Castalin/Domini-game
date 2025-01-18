#include "mainwindow.h"

MainWindow::MainWindow()
{
    WinConstants init;
    m_windowSize = {init.WIDTH, init.HEIGHT};
    m_window.create(sf :: VideoMode(init.WIDTH, init.HEIGHT), init.TITLE, sf :: Style :: Titlebar | sf::Style::Close);
    m_window.setFramerateLimit(init.FRAMERATE);
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

void MainWindow::draw(const sf::Drawable &elem)
{
    m_window.draw(elem);
}

const sf::Vector2u &MainWindow::getwindowSize() const
{
    return m_windowSize;
}
