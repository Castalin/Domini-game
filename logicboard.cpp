#include "logicboard.h"

LogicBoard::LogicBoard()
    : CasualBoard()
{

    m_gameBoard = std :: vector<std :: vector<char>>(m_rows, std :: vector<char>(m_columns, ','));

    reset();
}

LogicBoard::~LogicBoard()
{

}

void LogicBoard::reset()
{

    for (int i{0}; i < m_countCells; i++)
    {
        m_gameBoard[i / m_rows][i % m_columns] = ',';
    }

    for (int i{0}; i < m_countFig; i++)
    {
        m_gameBoard[i / m_rowsFig][i % m_columnsFig] = '2';                                                       // the second player's figures

        m_gameBoard[m_rows - 1 - i / m_rowsFig][m_columns - 1 - i % m_columnsFig] = '1';
    }
    m_turn = PLAYER_1;
}

bool LogicBoard::checkSelectable(const sf::Vector2i &indexes)
{
    if (m_turn == PLAYER_1)
    {
        return m_gameBoard[indexes.x][indexes.y] == '1';
    }

    return m_gameBoard[indexes.x][indexes.y] == '2';
}

bool LogicBoard::checkEmpty(const sf::Vector2i &indexes)
{
    return m_gameBoard[indexes.x][indexes.y] == ',';
}

void LogicBoard::moveFigure(const sf::Vector2i &oldPos, const sf::Vector2i &newPos)
{
    std :: swap(m_gameBoard[oldPos.x][oldPos.y], m_gameBoard[newPos.x][newPos.y]);
    m_turn = (m_turn == PLAYER_1 ? PLAYER_2 : PLAYER_1);
}
