#include "figure.h"

Figure::Figure(Colors color)
    :m_indexes(0, 0), m_color{color}
{

}

bool Figure::checkCell(const sf::Vector2i &newIndexes)
{
    return (abs(m_indexes.x - newIndexes.x) + abs(m_indexes.y - newIndexes.y)) == 1;
}

void Figure::setIndexes(const sf :: Vector2i &newIndexes)
{
    m_indexes = newIndexes;
}

int Figure::getindexX() const
{
    return m_indexes.x;
}

int Figure::getindexY() const
{
    return m_indexes.y;
}

const sf::Vector2i &Figure::getIndexes() const
{
    return m_indexes;
}
