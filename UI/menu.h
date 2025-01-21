#ifndef MENU_H
#define MENU_H
#include "abstarct/a_window.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "UIboard.h"

class Menu : public A_window
{
public:
    Menu(sf :: RenderWindow *window, std :: shared_ptr<UIBoard> UIboard);

    void handleInput(sf::Event &event) override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf :: RenderWindow *m_window;
    sf :: Text m_startText;
    sf :: Text m_quitText;
    sf :: Font m_font;

    std::shared_ptr<UIBoard> m_UIboard;
};

#endif // MENU_H
