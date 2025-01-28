#include "endgame.h"

EndGame::EndGame(sf::RenderWindow *window, UIBoard *UIboard)
    :m_window{window}, m_UIboard{UIboard}
{
    m_font.loadFromFile("other\\Verdana.ttf");  /**/

    initText(m_message, "", 65u, sf :: Color(128u, 128u, 128u));
    m_message.setPosition(m_window->getSize().x / 2, m_window->getSize().y / 5);

    initText(m_menuText, "Menu", 25u, sf :: Color(128u, 128u, 128u));
    m_menuText.setPosition(m_window->getSize().x / 2, m_window->getSize().y * 5 / 10);

    initText(m_restartText, "Restart", 25u, sf :: Color(128u, 128u, 128u));
    m_restartText.setPosition(m_window->getSize().x / 2, m_window->getSize().y * 4 / 10);

}

void EndGame::handleInput(sf::Event &event)
{
    if (event.type == sf :: Event :: MouseButtonPressed)
    {
        if (event.mouseButton.button == sf :: Mouse :: Left)
        {
            if (inArea(m_restartText.getGlobalBounds(), event) == true)
            {
                m_UIboard->reset();
                *(m_winState.get()) = WinState :: GAME;
            }
            if (inArea(m_menuText.getGlobalBounds(), event) == true)
            {
                *(m_winState.get()) = WinState :: MAIN_MENU;
            }
        }
    }
}

void EndGame::setMessage(const std::string &message)
{
    m_message.setString(message);
    centralize(m_message);
    m_message.setPosition(m_window->getSize().x / 2, m_window->getSize().y / 5);
}

void EndGame::centralize(sf::Text &text)
{
    text.setOrigin(text.getLocalBounds().getSize().x / 2, text.getLocalBounds().getSize().y / 2);
}

void EndGame::initText(sf::Text &text, const std :: string &str, const unsigned int &size, const sf :: Color &color)
{
    text.setFont(m_font);
    text.setString(str);
    text.setCharacterSize(size);
    centralize(text);
    text.setFillColor(color);
}

void EndGame::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_message);
    target.draw(m_restartText);
    target.draw(m_menuText);
}
