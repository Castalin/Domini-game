#ifndef ENDGAME_H
#define ENDGAME_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "UIboard.h"

class UIBoard;

class EndGame : public A_window
{
public:
    EndGame(sf::RenderWindow *window, UIBoard* UIboard);

    void handleInput(sf::Event &event) override;
    void setMessage(const std :: string &message);
private:
    sf :: RenderWindow *m_window;
    sf :: Text m_restartText;
    sf :: Text m_menuText;
    sf :: Text m_message;
    sf :: Font m_font;

    UIBoard* m_UIboard;

    void centralize(sf::Text &text);
    void initText(sf::Text &text, const std::string &str, const unsigned int &size, const sf::Color &color);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // ENDGAME_H
