#ifndef I_HANDLEINPUT_H
#define I_HANDLEINPUT_H
#include "SFML/Window/Event.hpp"

class I_handleInput
{
public:
    I_handleInput();
    virtual ~I_handleInput();

    virtual void handleInput(sf :: Event &event) = 0;

};

#endif // I_HANDLEINPUT_H
