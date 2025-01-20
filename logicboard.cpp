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
    m_madeMove = false;
}

bool LogicBoard::checkSelectable(const sf::Vector2i &indexes)
{
    if (m_turn == PLAYER_1)
    {
        return m_gameBoard[indexes.x][indexes.y] == '1';
    }

    return m_gameBoard[indexes.x][indexes.y] == '2';
}

bool LogicBoard::checkEmptyCell(const sf::Vector2i &indexes)
{
    return m_gameBoard[indexes.x][indexes.y] == ',';
}

void LogicBoard::moveFigure(const sf::Vector2i &oldPos, const sf::Vector2i &newPos)
{
    std :: swap(m_gameBoard[oldPos.x][oldPos.y], m_gameBoard[newPos.x][newPos.y]);
    m_turn = (m_turn == PLAYER_1 ? PLAYER_2 : PLAYER_1);
    m_madeMove = true;
}

bool LogicBoard::checkWinner()
{
    if (m_madeMove == true)
    {
        int countPlayer1{0};
        int countPlayer2{0};
        for (int i{0}; i < m_countFig; i++)
        {
            if (m_gameBoard[i / m_rowsFig][i % m_columnsFig] == '1')
            {
                countPlayer1++;
            }
            if (m_gameBoard[m_rows - 1 - i / m_rowsFig][m_columns - 1 - (i % m_columnsFig)] == '2')
            {
                countPlayer2++;
            }
        }
        if (countPlayer1 == m_countFig)
        {
            m_message = std :: string("You Won!");
            return true;
        }

        if (countPlayer2 == m_countFig)
        {
            m_message = std :: string("Game over");
            return true;
        }
    }
    return false;

}

const std::string& LogicBoard::getMessage()
{
    return m_message;
}
