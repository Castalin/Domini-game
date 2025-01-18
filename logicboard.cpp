#include "logicboard.h"

LogicBoard::LogicBoard(BoardConstants &boardConst)
    :m_rows{boardConst.rows}, m_columns{boardConst.columns}, m_rowsFig{boardConst.rowsFig}, m_columnsFig{boardConst.columnsFig},
    m_countFigures{m_rowsFig * m_columnsFig}, m_teams{MAX_PLAYERS}
{
    m_factory = std :: make_unique<FigureFactory>();
    m_figures = std :: vector<std :: vector<std :: shared_ptr<Figure>>>(MAX_PLAYERS, std :: vector<std :: shared_ptr<Figure>>());
    createFigures(*m_factory.get(), PLAYER_1, Colors :: WHITE);
    createFigures(*m_factory.get(), PLAYER_2, Colors :: BLACK);

    m_gameBoard = std :: vector<std :: vector<char>>(m_rows, std :: vector<char>(m_columns, ','));

    reset();

}

LogicBoard::~LogicBoard()
{

}

std::vector<std::vector<std::shared_ptr<Figure>>>* LogicBoard::getfigures()
{
    return &m_figures;
}

void LogicBoard::createFigures(FigureFactory &factory, const Players &player, const Colors &color)
{
    for (int i{0}; i < m_countFigures; ++i)
    {
        m_figures[player].push_back(factory.createFigure(color));
    }
}

void LogicBoard::reset()
{
    for (int i{0}; i < m_rows * m_columns; i++)
    {
        m_gameBoard[i / m_rows][i % m_columns] = ',';
    }

    for (int i{0}; i < m_countFigures; i++)
    {
        m_gameBoard[i / m_rowsFig][i % m_columnsFig] = '2';                                                       // the second player's figures
        m_figures[PLAYER_2][i]->setIndexes(i / m_rowsFig, i % m_columnsFig);                                      //fill the gameboard 3x3 from the end


        m_gameBoard[m_rows - 1 - i / m_rowsFig][m_columns - 1 - i % m_columnsFig] = '1';
        m_figures[PLAYER_1][i]->setIndexes(m_rows - 1 - i / m_rowsFig, m_columns - 1 - i % m_columnsFig);  //fill the gameboard 3x3 from the end
    }

}
