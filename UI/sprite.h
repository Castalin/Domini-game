#ifndef SPRITE_H
#define SPRITE_H

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Sprite : public sf :: Sprite
{
public:
    Sprite();

    void loadFromFile(const std :: string &filePath);
    void loadFromImage(const sf :: Image &image);
    void centrelizeOrigin();

private:
    sf :: Texture m_sfTexture;
    bool m_valid;
    void setTexture(const sf :: Texture &texture, bool resetRect = false);
    void setTextureRect(const sf :: IntRect &rect);
};

#endif // SPRITE_H
