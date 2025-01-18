#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SFML/Graphics.hpp"
#include "UI/winconstants.h"

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();

    MainWindow(const MainWindow &window) = delete;
    MainWindow& operator= (const MainWindow &window) = delete;
    void clear();
    void update();
    void display();

    bool isOpen() const;
    void draw(const sf :: Drawable &elem);

    const sf::Vector2u& getwindowSize() const;

private:
    sf :: RenderWindow m_window;
    sf :: Vector2u m_windowSize;
};

#endif // MAINWINDOW_H
