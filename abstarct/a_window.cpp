#include "a_window.h"

A_window::A_window()
{

}

A_window::~A_window()
{

}

const WinState &A_window::getState() const
{
    return *(m_winState.get());
}

bool A_window::inArea(const sf::FloatRect &rect, const sf::Event &event)
{
    return rect.contains(event.mouseButton.x, event.mouseButton.y);
}

void A_window :: setState(std :: shared_ptr<WinState> state)
{
    m_winState = state;
}
