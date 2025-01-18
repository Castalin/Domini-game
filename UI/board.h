#ifndef BOARD_H
#define BOARD_H
#include "mainwindow.h"
#include "sprite.h"
#include <Figure.h>
#include <vector>
#include "boardconstants.h"
#include <memory>


class Board
{
public:
    Board(MainWindow * const mainWindow, BoardConstants &boardConst);

    void draw() const;
    void setFigures(std :: vector<std :: vector<std :: shared_ptr<Figure>>> *figures);

private:
    MainWindow *m_mainWindow;
    const sf :: Vector2u &m_windowSize;

    Sprite m_spriteBound;
    Sprite m_spriteBoard;

    float m_widthOfCell;
    float m_heightOfCell;
    sf :: Vector2f m_startCell;
    std :: vector<std :: vector<std :: shared_ptr<Figure>>> *m_figures;
};

#endif // BOARD_H
