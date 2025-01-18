#include "sprite.h"

Sprite::Sprite()
{
    m_valid = false;
}

void Sprite::loadFromFile(const std::string &filePath)
{
    if (m_sfTexture.loadFromFile(filePath) == true)
    {
        m_valid = true;
        this->setTexture(m_sfTexture);
    }
}

void Sprite::loadFromImage(const sf::Image &image)
{
    if (m_sfTexture.loadFromImage(image) == true)
    {
        m_valid = true;
        this->setTexture(m_sfTexture);
    }
}

void Sprite::centrelizeOrigin()
{
    if (m_valid == true)
    {
        this->setOrigin(m_sfTexture.getSize().x / 2, m_sfTexture.getSize().y / 2);
    }
}

void Sprite::setTexture(const sf::Texture &texture, bool resetRect)
{
    sf :: Sprite :: setTexture(texture, resetRect);
}

void Sprite::setTextureRect(const sf::IntRect &rect)
{
    sf :: Sprite :: setTextureRect(rect);
}

