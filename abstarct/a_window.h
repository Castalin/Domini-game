#ifndef A_WINDOW_H
#define A_WINDOW_H
#include "i_window.h"
#include <memory>


enum class WinState
{
    MAIN_MENU           = 0,
    GAME                = 1,
    END_GAME            = 2
};

class A_window : public I_window
{
public:
    A_window();
    virtual ~A_window();

    void handleInput(sf::Event &event) override = 0;
    const WinState& getState() const;
    void setState(std :: shared_ptr<WinState> state);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;
    std :: shared_ptr<WinState> m_winState;
    bool inArea(const sf::FloatRect &rect, const sf::Event &event);
};

#endif // A_WINDOW_H
