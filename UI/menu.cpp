#include "menu.h"

Menu::Menu(sf::RenderWindow *window)
    :m_window{window}
{
    m_font.loadFromFile("..\\Domini-game\\UI\\other\\Verdana.ttf");
    m_startText.setString("Start");
    m_startText.setFont(m_font);
    m_startText.setCharacterSize(50);
    m_startText.setOrigin(m_startText.getLocalBounds().getSize().x / 2, m_startText.getLocalBounds().getSize().y / 2);
    m_startText.setFillColor(sf :: Color(128, 128, 128));
    m_startText.setPosition(m_window->getSize().x / 2, m_window->getSize().y / 3);

    m_quitText.setString("Quit");
    m_quitText.setFont(m_font);
    m_quitText.setCharacterSize(25);
    m_quitText.setOrigin(m_quitText.getLocalBounds().getSize().x / 2, m_quitText.getLocalBounds().getSize().y / 2);
    m_quitText.setFillColor(sf :: Color(128, 128, 128));
    m_quitText.setPosition(m_window->getSize().x / 2, m_window->getSize().y / 2);
}

void Menu::handleInput(sf::Event &event)
{
    if (event.type == sf :: Event :: MouseButtonPressed)
    {
        if (event.mouseButton.button == sf :: Mouse :: Left)
        {
            if (inArea(m_startText.getGlobalBounds(), event) == true)
            {
                *(m_winState.get()) = WinState :: GAME;
            }
            if (inArea(m_quitText.getGlobalBounds(), event) == true)
            {
                m_window->close();
            }
        }
    }
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_startText);
    target.draw(m_quitText);
}
