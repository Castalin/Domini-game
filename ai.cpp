#include "ai.h"
#include <cfloat>

AI::AI(const board *gameBoard, const vector<std :: shared_ptr<Figure>> *figures, playerType type)
    :m_gameBoard{gameBoard}, m_figures{figures}, m_playerType{type}, m_rows(gameBoard->size()), m_columns(gameBoard[0].size())
{
    m_points = vector< vector<float>>(m_rows, vector<float>(m_columns, 1.0f));
    float step = 0.05f;
    for (int i{1}; i < m_columns; ++i)
    {
        m_points[0][i] = m_points[0][i - 1] + step;
    }

    for (int i{1}; i < m_rows; ++i)
    {
        for (int j{0}; j < m_columns; ++j)
        {
            m_points[i][j] = m_points[i - 1][j] + step;
        }
    }

    m_optimalCell = {-1, -1};
    m_optimalFig = {-1, -1};
}

void AI::findOptimal()
{
    float diff{-FLT_MAX};
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

void AI::findOptimalCell(const Figure &fig, float &diff)
{
    for (auto &newPos : m_possibleMoves)
    {
        if (countDiff(newPos, fig.getIndexes()) >= diff)
        {
            m_optimalFig = fig.getIndexes();
            m_optimalCell = newPos;
            diff = countDiff(newPos, fig.getIndexes());
        }
    }
}

float AI::countDiff(const Vector2i &newPos, const Vector2i &pos)
{
    return m_points[newPos.x][newPos.y] - m_points[pos.x][pos.y];
}


