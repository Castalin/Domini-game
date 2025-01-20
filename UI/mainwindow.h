#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "SFML/Graphics.hpp"
#include "winconstants.h"
#include "UIboard.h"
#include "menu.h"
#include "unordered_map"
#include "endgame.h"

class MainWindow
{
public:
    MainWindow(UIBoard *UIboard, WinConstants &winConst);
    ~MainWindow();

    MainWindow(const MainWindow &window) = delete;
    MainWindow& operator= (const MainWindow &window) = delete;

    void clear();
    void update();
    void display();

    bool isOpen() const;
    void draw();

    const sf::Vector2u& getwindowSize() const;

private:
    sf :: RenderWindow m_rendWindow;
    sf :: Vector2u m_windowSize;

    UIBoard *m_UIboard;

    std :: unique_ptr<Menu> m_menu;
    std :: unique_ptr<EndGame> m_endGame;
    std :: unordered_map<WinState, I_window*> m_stateWindows;
    const WinState *m_winState;

};

#endif // MAINWINDOW_H
