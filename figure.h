#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics/Sprite.hpp>
#include "abstarct/i_checkcell.h"
#include "cmath"

enum class Colors
{
    WHITE           = 0,
    BLACK           = 1
};


class Figure : public sf :: Sprite, public I_checkCell
{
public:
    Figure(Colors color);

    bool checkCell(const sf::Vector2i &newIndexes) override;

    void setIndexes(const sf::Vector2i &newIndexes);
    int getindexX() const;
    int getindexY() const;
    const sf :: Vector2i& getIndexes() const;

private:
    sf :: Vector2i m_indexes;
    const Colors m_color;

};

#endif // FIGURE_H
