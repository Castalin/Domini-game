#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics/Sprite.hpp>

enum class Colors
{
    WHITE           = 0,
    BLACK           = 1
};


class Figure : public sf :: Sprite
{
public:
    Figure(Colors color);
    void setIndexes(const int &x, const int &y);

    int getindexX() const;

    int getindexY() const;

private:
    int m_indexX;
    int m_indexY;
    const Colors m_color;

};

#endif // FIGURE_H
