#include "figure.h"

Figure::Figure(Colors color)
    :m_color{color}
{

    m_indexX = 0;
    m_indexY = 0;
}

void Figure::setIndexes(const int &x, const int &y)
{
    m_indexX = x;
    m_indexY = y;
}

int Figure::getindexX() const
{
    return m_indexX;
}

int Figure::getindexY() const
{
    return m_indexY;
}
