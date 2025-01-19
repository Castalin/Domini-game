#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SFML/Graphics.hpp"
#include "UI/winconstants.h"
#include "UIboard.h"

class MainWindow
{
public:
    MainWindow(UIBoard *UIboard, WinConstants &winConst);
    ~MainWindow();

    MainWindow(const MainWindow &window) = delete;
    MainWindow& operator= (const MainWindow &window) = delete;

    void pollEvent(sf :: Event &event);
    void clear();
    void update();
    void display();

    bool isOpen() const;
    void draw();

    const sf::Vector2u& getwindowSize() const;

private:
    sf :: RenderWindow m_window;
    sf :: Vector2u m_windowSize;
    UIBoard *m_UIboard;
};

#endif // MAINWINDOW_H
