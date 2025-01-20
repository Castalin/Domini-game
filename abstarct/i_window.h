#ifndef I_WINDOW_H
#define I_WINDOW_H

#include "abstarct/i_handleinput.h"
#include <SFML/Graphics/Drawable.hpp>

class I_window : public I_handleInput, public sf :: Drawable
{
public:
    I_window();
    virtual ~I_window();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
    void handleInput(sf::Event &event) override = 0;
};

#endif // I_WINDOW_H
