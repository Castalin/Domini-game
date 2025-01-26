#include "UIboard.h"
#include "endgame.h"
#include "SFML/Graphics/RenderTarget.hpp"

UIBoard :: UIBoard(std::shared_ptr<LogicBoard> logicBoard, const WinConstants &winConst)
    : m_windowSize(sf :: Vector2u{winConst.WIDTH, winConst.HEIGHT}), m_logicBoard(logicBoard)
{
    m_spriteBound.loadFromFile("other\\bound.jpg"); /*..\\Domini-game\\UI\\*/

    m_spriteBoard.loadFromFile("other\\board.png");
    m_spriteBoard.centrelizeOrigin();
    m_spriteBoard.setPosition(m_windowSize.x / 2, m_windowSize.y / 2);

    m_widthOfCell = m_spriteBoard.getTexture()->getSize().x / m_columns;
    m_heightOfCell = m_spriteBoard.getTexture()->getSize().y / m_rows;

    m_startCell = {m_spriteBoard.getGlobalBounds().left, m_spriteBoard.getGlobalBounds().top};
    m_startCell.x += m_widthOfCell * 0.5f;
    m_startCell.y += m_heightOfCell * 0.5f;

    m_font.loadFromFile("other\\Verdana.ttf"); /**/

    m_refreshText.setString("To restart press F5");
    m_refreshText.setFont(m_font);
    m_refreshText.setCharacterSize(25u);
    m_refreshText.setFillColor(sf :: Color(128u, 128u, 128u));                                        //gray
    m_refreshText.setPosition(5.f, m_windowSize.y - m_refreshText.getCharacterSize() * 1.1f);


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

void UIBoard::unselectFig()
{
    m_selectedFigure = nullptr;
    m_possibleMovesPoints.clear();
}

bool UIBoard::moveFigure(const sf::Vector2i &newIndexes)
{
    if (setNewIndexes(newIndexes) == true)
    {
        setPosition(m_selectedFigure);
        return true;
    }
    return false;

}

void UIBoard::createPossibleMovePoint(const int &x, const int &y)
{
    sf :: CircleShape point(m_widthOfCell / 10);
    point.setFillColor(sf :: Color(0, 0, 0));
    point.setOutlineThickness(point.getRadius() / 10);
    point.setOutlineColor(sf :: Color(224, 224, 224));
    point.setPosition(x * m_widthOfCell + m_startCell.x, y * m_heightOfCell + m_startCell.y);
    m_possibleMovesPoints.push_back(point);
}

void UIBoard::calculatePossibleMoves()
{
    if (!isFigSelected())
        return;

    for (int x{0}; x < m_rows; ++x)
        for (int y{0}; y < m_columns; ++y)
            if (m_selectedFigure->checkCell({x, y}) == true && m_logicBoard->checkEmptyCell({x, y}))
                createPossibleMovePoint(x, y);
}

void UIBoard::setPosition(Figure *fig)
{
    fig->setPosition(fig->getindexX() * m_widthOfCell + m_startCell.x, fig->getindexY() * m_heightOfCell + m_startCell.y);
}

bool UIBoard::setNewIndexes(const Vector2i &newIndexes)
{
    if (m_selectedFigure->checkCell(newIndexes) == true && m_logicBoard->checkEmptyCell(newIndexes))
    {
        m_logicBoard->moveFigure(m_selectedFigure->getIndexes(), newIndexes);
        m_selectedFigure->setIndexes(newIndexes);
        return true;
    }
    return false;
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
        for (auto &fig : vec)
            setPosition(fig.get());


    unselectFig();
    m_logicBoard->reset();
}

void UIBoard::selectFigure(const sf::Vector2i &indexes)
{
    if (m_logicBoard->checkSelectable(indexes) == true)
    {
        m_selectedFigure = findFigure(indexes);
    }
}

bool UIBoard::tryToMoveFigure(const sf::Vector2i &newIndexes)
{
    if (isFigSelected())
    {
        bool success = moveFigure(newIndexes);
        unselectFig();
        return success;
    }
    return false;

}

void UIBoard::checkGameState()
{
    if (m_logicBoard->checkWinner() == true)
    {
        m_endGame->setMessage(m_logicBoard->getMessage());
        *(m_winState.get()) = WinState :: END_GAME;
    }
}

void UIBoard::setEndGameWindow(std::shared_ptr<EndGame> endGame)
{
    m_endGame = endGame;
}

void UIBoard::handleInput(sf::Event &event)
{
    if (event.type == sf :: Event :: KeyPressed)
    {
        switch  (event.key.code)
        {
            case sf :: Keyboard :: Escape:
            {
                *(m_winState.get()) = WinState :: MAIN_MENU;
                unselectFig();
                break;
            }
            case sf :: Keyboard :: F5:
            {
                reset();
                break;
            }
        }
    }

    if (event.type == sf :: Event :: MouseButtonPressed)
    {
        if (event.mouseButton.button == sf :: Mouse :: Left)
        {
            if (inArea(m_spriteBoard.getGlobalBounds(), event) == true)
            {
                auto rect = m_spriteBoard.getGlobalBounds();
                sf :: Vector2i indexes((event.mouseButton.x - rect.left) / m_widthOfCell, (event.mouseButton.y - rect.top) / m_heightOfCell);
                selectFigure(indexes);
                calculatePossibleMoves();
            }
        }
    }

    if (event.type == sf :: Event :: MouseMoved)
    {
        if (isFigSelected())
        {
            m_selectedFigure->setPosition(event.mouseMove.x, event.mouseMove.y);
        }
    }

    if (event.type == sf :: Event :: MouseButtonReleased)
    {
        if (event.mouseButton.button == sf :: Mouse :: Left)
        {
            if (isFigSelected())
            {
                if (inArea(m_spriteBoard.getGlobalBounds(), event) == true)
                {
                    auto rect = m_spriteBoard.getGlobalBounds();
                    sf :: Vector2i indexes((event.mouseButton.x - rect.left) / m_widthOfCell, (event.mouseButton.y - rect.top) / m_heightOfCell);
                    setNewIndexes(indexes);
                    checkGameState();
                }
                setPosition(m_selectedFigure);
                unselectFig();
            }
        }
    }
}

const std::vector<std::shared_ptr<Figure> > *UIBoard::getPlayerFigure(const Players &player)
{
    return &m_figures[player];
}

void UIBoard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_spriteBound);
    target.draw(m_spriteBoard);
    target.draw(m_refreshText);

    for (auto &point : m_possibleMovesPoints)
        target.draw(point);


    for (auto &vec : m_figures)
        for (auto &fig : vec)
            target.draw(*fig);
}

UIBoard::~UIBoard()
{

}
