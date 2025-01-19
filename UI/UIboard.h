#ifndef UIBOARD_H
#define UIBOARD_H
#include "sprite.h"
#include "../Domini-game/figurefactory.h"
#include "../Domini-game/logicboard.h"
#include "winconstants.h"
#include "SFML/Window.hpp"


class UIBoard : public CasualBoard, public sf::Drawable
{
public:
    UIBoard(LogicBoard * logicBoard, const WinConstants &winConst);
    ~UIBoard();

    void reset();
    void handeInput(sf :: Event &event);
    void selectFigure(const sf :: Vector2i &indexes);
    void tryToMoveFigure(const sf :: Vector2i &newIndexes);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    const sf :: Vector2u m_windowSize;

    Sprite m_spriteBound;
    Sprite m_spriteBoard;

    float m_widthOfCell;
    float m_heightOfCell;
    std :: pair<int, int> m_widthBorder;
    std :: pair<int, int> m_heightBorder;
    sf :: Vector2f m_startCell;

    Figure *m_selectedFigure;

    LogicBoard *m_logicBoard;
    using Figures = std :: vector<std :: shared_ptr<Figure>>;
    std :: vector<Figures> m_figures;
    std :: unique_ptr<FigureFactory> m_factory;

    void createFigures(const LogicBoard :: Players &player, const Colors &color, const int &count);
    Figure* findFigure(const sf :: Vector2i &indexes);
    inline bool isFigSelected();
    void moveFigure(const sf :: Vector2i &newIndexes);

};

#endif // UIBOARD_H
