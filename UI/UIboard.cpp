#include "UIboard.h"
#include "SFML/Graphics/RenderTarget.hpp"

UIBoard :: UIBoard(LogicBoard * logicBoard, const WinConstants &winConst)
    : m_windowSize(sf :: Vector2u{winConst.WIDTH, winConst.HEIGHT}), m_logicBoard(logicBoard)
{
    m_spriteBound.loadFromFile("D:\\stud\\ProgaForQt\\dominiGame\\DominiGame\\Domini-game\\UI\\photos\\bound.jpg");

    m_spriteBoard.loadFromFile("D:\\stud\\ProgaForQt\\dominiGame\\DominiGame\\Domini-game\\UI\\photos\\board.png");
    m_spriteBoard.centrelizeOrigin();
    m_spriteBoard.setPosition(m_windowSize.x / 2, m_windowSize.y / 2);

    m_widthOfCell = m_spriteBoard.getTexture()->getSize().x / m_columns;
    m_heightOfCell = m_spriteBoard.getTexture()->getSize().y / m_rows;

    m_startCell = m_spriteBoard.getPosition();
    m_startCell.x -= m_widthOfCell * m_rows / 2;
    m_startCell.y -= m_heightOfCell * m_columns / 2;

    m_widthBorder = std :: make_pair(m_startCell.x, m_startCell.x + m_spriteBoard.getTexture()->getSize().x);
    m_heightBorder = std :: make_pair(m_startCell.y, m_startCell.y + m_spriteBoard.getTexture()->getSize().y);

    m_startCell.x += m_widthOfCell * 0.5;
    m_startCell.y += m_heightOfCell * 0.5;


    m_factory = std :: make_unique<FigureFactory>();
    m_figures = std :: vector<Figures>(MAX_PLAYERS, Figures());
    createFigures(PLAYER_1, Colors :: WHITE, m_columnsFig * m_rowsFig);
    createFigures(PLAYER_2, Colors :: BLACK, m_columnsFig * m_rowsFig);

    reset();
}


void UIBoard::createFigures(const LogicBoard::Players &player, const Colors &color, const int &count)
{
    for (int i{0}; i < count; ++i)
    {
        m_figures[player].push_back(m_factory->createFigure(color));
    }
}

Figure *UIBoard::findFigure(const sf::Vector2i &indexes)
{
    for (auto &vec : m_figures)
    {
        for (auto &fig : vec)
        {
            if (fig->getIndexes() == indexes)
            {
                return fig.get();
            }
        }
    }
    return nullptr;
}

bool UIBoard::isFigSelected()
{
    return m_selectedFigure != nullptr;
}

void UIBoard::moveFigure(const sf::Vector2i &newIndexes)
{
    if (m_selectedFigure->checkCell(newIndexes) == true && m_logicBoard->checkEmpty(newIndexes))
    {
        m_logicBoard->moveFigure(m_selectedFigure->getIndexes(), newIndexes);
        m_selectedFigure->setIndexes(newIndexes);
        m_selectedFigure->setPosition(newIndexes.x * m_widthOfCell + m_startCell.x, newIndexes.y * m_heightOfCell + m_startCell.y);
    }
    m_selectedFigure = nullptr;
}

void UIBoard::reset()
{
    int indexX{0};
    int indexY{0};
    for (int i{0}; i < m_countFig; ++i)
    {
        indexX = i / m_rowsFig;
        indexY = i % m_columnsFig;

        m_figures[PLAYER_2][i]->setIndexes(sf :: Vector2i(indexX, indexY));
        m_figures[PLAYER_1][i]->setIndexes(sf :: Vector2i(m_rows - 1 - indexX, m_columns - 1 - indexY));    //fill the gameboard 3x3 from the end
    }

    for (auto &vec : m_figures)
    {
        for (auto &fig : vec)
        {
            fig->setPosition(fig->getindexX() * m_widthOfCell + m_startCell.x, fig->getindexY() * m_heightOfCell + m_startCell.y);
        }
    }
    m_selectedFigure = nullptr;
}

void UIBoard::handeInput(sf::Event &event)
{
    if (event.type == sf :: Event :: MouseButtonPressed)
    {
        if (event.mouseButton.button == sf :: Mouse :: Left)
        {
            if (event.mouseButton.x >= m_widthBorder.first && event.mouseButton.x <= m_widthBorder.second &&
                event.mouseButton.y >= m_heightBorder.first && event.mouseButton.y <= m_heightBorder.second)
            {
                sf :: Vector2i indexes((event.mouseButton.x - m_widthBorder.first) / m_widthOfCell, (event.mouseButton.y - m_heightBorder.first) / m_heightOfCell);

                if (isFigSelected())
                {
                    moveFigure(indexes);
                }
                else
                {
                    selectFigure(indexes);
                }
            }
            else
            {
                m_selectedFigure = nullptr;
            }
        }
    }
}

void UIBoard::selectFigure(const sf::Vector2i &indexes)
{
    if (m_logicBoard->checkSelectable(indexes) == true)
    {
        m_selectedFigure = findFigure(indexes);
    }
}

void UIBoard::tryToMoveFigure(const sf::Vector2i &newIndexes)
{
    if (isFigSelected())
    {
        moveFigure(newIndexes);
    }
}

void UIBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_spriteBound);
    target.draw(m_spriteBoard);

    for (auto &vec : m_figures)
    {
        for (auto &fig : vec)
        {
            target.draw(*fig);
        }
    }
}

UIBoard::~UIBoard()
{

}
