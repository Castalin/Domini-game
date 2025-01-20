#include "figurefactory.h"
#include "SFML/Graphics/Texture.hpp"

FigureFactory::FigureFactory()
{
    std :: string pathToTexture = "D:\\stud\\ProgaForQt\\dominiGame\\DominiGame\\Domini-game\\UI\\other\\";;
    std :: string pathPostfix = "_pawn.png";
    m_mapTextures[Colors :: WHITE] = sf :: Texture();
    m_mapTextures[Colors :: WHITE].loadFromFile(pathToTexture + "white" + pathPostfix);
    m_mapTextures[Colors :: BLACK] = sf :: Texture();
    m_mapTextures[Colors :: BLACK].loadFromFile(pathToTexture + "black" + pathPostfix);
}

FigureFactory::~FigureFactory()
{

}

std::shared_ptr<Figure> FigureFactory::createFigure(Colors color)
{
    auto figure = std :: make_shared<Figure>(color);
    figure->setTexture(m_mapTextures[color]);
    figure->setOrigin(m_mapTextures[color].getSize().x / 2, m_mapTextures[color].getSize().y / 2);
    return figure;

}
