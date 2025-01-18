#include "board.h"

Board::Board(MainWindow * const mainWindow, BoardConstants &boardConst)
    : m_mainWindow(mainWindow), m_windowSize(mainWindow->getwindowSize()), m_figures{nullptr}
{
    m_spriteBound.loadFromFile("D:\\stud\\ProgaForQt\\dominiGame\\DominiGame\\Domini-game\\UI\\photos\\bound.jpg");

    m_spriteBoard.loadFromFile("D:\\stud\\ProgaForQt\\dominiGame\\DominiGame\\Domini-game\\UI\\photos\\board.png");
    m_spriteBoard.centrelizeOrigin();
    m_spriteBoard.setPosition(m_windowSize.x / 2, m_windowSize.y / 2);

    m_widthOfCell = m_spriteBoard.getTexture()->getSize().x / boardConst.columns;
    m_heightOfCell = m_spriteBoard.getTexture()->getSize().y / boardConst.rows;

    m_startCell = m_spriteBoard.getPosition();
    m_startCell.x -= m_widthOfCell * boardConst.rows / 2;
    m_startCell.y -= m_heightOfCell * boardConst.columns / 2;
    m_startCell.x += m_widthOfCell * 0.5;
    m_startCell.y += m_heightOfCell * 0.5;

}

void Board::draw() const
{
    m_mainWindow->draw(m_spriteBound);
    m_mainWindow->draw(m_spriteBoard);

    for (auto &vec : *m_figures)
    {
        for (auto &fig : vec)
        {

            fig->setPosition(fig->getindexX() * m_widthOfCell + m_startCell.x, fig->getindexY() * m_heightOfCell + m_startCell.y);
            m_mainWindow->draw(*fig);
        }
    }
}

void Board::setFigures(std::vector<std::vector<std::shared_ptr<Figure> > > *figures)
{
    m_figures = figures;
}

