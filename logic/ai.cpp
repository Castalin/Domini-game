#include "ai.h"
#include <cfloat>
#include <ctime>

AI::AI(const board *gameBoard, const vector<std :: shared_ptr<Figure>> *figures, playerType type)
    :m_gameBoard{gameBoard}, m_figures{figures}, m_playerType{type}, m_rows(gameBoard->size()), m_columns(gameBoard[0].size())
{
    m_points = vector< vector<int>>(m_rows, vector<int>(m_columns, 1));

                                                                                //        {1,  2, 4, 7, 11, 16, 22, 29},
    int step{1};                                                                //        {2,  1, 1, 1, 1,  1,  1,  1},
    for (int i{1}; i < m_rows; ++i)                                             //        {4,  1, 1, 1, 1,  1,  1,  1},
    {                                                                           //        {7,  1  1, 1, 1,  1,  1,  1},
        m_points[0][i] = step + m_points[0][i - 1];                             //        {11, 1, 1, 1, 1,  1,  1,  1},
        m_points[i][0] = step + m_points[i - 1][0];                             //        {16, 1, 1, 1, 1,  1,  1,  1},
        step++;                                                                 //        {22, 1, 1, 1, 1,  1,  1,  1},
    }                                                                           //        {29, 1, 1, 1, 1,  1,  1,  1}

    for (int i{1}; i < m_rows; ++i)                                             //        {1,  2,  4,  7,  11, 16,  22,   29},
    {                                                                           //        {2,  5,  9,  14, 20, 27,  35,   44},
        step = 3 * i;                                                           //        {4,  9,  15, 22, 30, 39,  49,   60},
        for (int j{i}; j < m_columns; ++j)                                      //        {7,  14, 22, 31, 41, 52,  64,   77},
        {                                                                       //        {11, 20, 30, 41, 53, 66,  80,   95},
            m_points[i][j] = m_points[i][j - 1] + step;                         //        {16, 27, 39, 52, 66, 81,  97,   114},
            m_points[j][i] = m_points[j - 1][i] + step;                         //        {22, 35, 49, 64, 80, 97,  115,  134},
            step++;                                                             //        {29, 44, 60, 77, 95, 114, 134,  155}
        }                                                                       // this only works for square board
    }                                                                           // difference beetwen point (gradient) distributed from topleft corner
                                                                                // to the bottom right corner, AI try to get as much point per move as possible
                                                                                // the more closer figure to the right diagonal the more points it could have
                                                                                 // this is the fastest way to get right corner

    std :: srand(std :: time(0));
    m_optimalCell = {0, 0};
    m_optimalFig = {0, 0};
}

void AI::findOptimal()
{
    int diff{INT_MIN};
    for (auto &fig : *m_figures)
    {
        findPossibleMoves(*fig);
        findOptimalCell(*fig, diff);
        m_possibleMoves.clear();
    }
}

playerType AI::getplayerType() const
{
    return m_playerType;
}

Vector2i AI::getoptimalFig() const
{
    return m_optimalFig;
}

Vector2i AI::getoptimalCell() const
{
    return m_optimalCell;
}

void AI::findPossibleMoves(const Figure &fig)
{
    for (int i{0}; i < m_rows; ++i)
    {
        for (int j{0}; j < m_columns; ++j)
        {
            if (fig.checkCell({i, j}) == true && m_gameBoard->at(i)[j] == ',')
            {
                m_possibleMoves.push_back({i, j});
            }
        }
    }
}

void AI::findOptimalCell(const Figure &fig, int &diff)
{
    for (auto &newPos : m_possibleMoves)
    {
        int localDiff = countDiff(newPos, fig.getIndexes());
        if (localDiff >= diff)
        {
            if (diff == localDiff)
            {
                if (std :: rand() % 2 == 0)                      //random choice between moves with the same point result
                {
                    m_optimalFig = fig.getIndexes();
                    m_optimalCell = newPos;
                }
            }
            else
            {
                m_optimalFig = fig.getIndexes();
                m_optimalCell = newPos;
                diff = localDiff;
            }
        }
    }
}

int AI::countDiff(const Vector2i &newPos, const Vector2i &pos)
{
    return m_points[newPos.x][newPos.y] - m_points[pos.x][pos.y];
}


