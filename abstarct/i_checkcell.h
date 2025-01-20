#ifndef I_CHECKCELL_H
#define I_CHECKCELL_H

#include "SFML/System/Vector2.hpp"

class I_checkCell
{
public:
    I_checkCell();
    virtual ~I_checkCell();
    virtual bool checkCell(const sf :: Vector2i &newIndexes) const = 0;
};

#endif // I_CHECKCELL_H
