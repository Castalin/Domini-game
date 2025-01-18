#ifndef FIGUREFACTORY_H
#define FIGUREFACTORY_H
#include "figure.h"
#include <map>
#include <memory>

class FigureFactory
{
public:
    FigureFactory();
    ~FigureFactory();
    std :: shared_ptr<Figure> createFigure(Colors color);


private:
    std :: map<Colors, sf :: Texture> m_mapTextures;
};

#endif // FIGUREFACTORY_H
