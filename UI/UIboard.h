#ifndef UIBOARD_H
#define UIBOARD_H
#include "sprite.h"
#include "logic/figurefactory.h"
#include "logic/logicboard.h"
#include "winconstants.h"
#include "SFML/Graphics/Text.hpp"
#include "abstarct/a_window.h"
#include "SFML/Graphics/CircleShape.hpp"

class EndGame;

class UIBoard : public CasualBoard, public A_window
{
public:
    UIBoard(LogicBoard * logicBoard, const WinConstants &winConst);
    ~UIBoard();

    void reset();
    inline bool isFigSelected();
    void selectFigure(const sf :: Vector2i &indexes);
    bool tryToMoveFigure(const sf :: Vector2i &newIndexes);
    void checkGameState();

    void setEndGameWindow(EndGame *endGame);

    void handleInput(sf::Event &event) override;
    const std :: vector<std :: shared_ptr<Figure>>* getPlayerFigure(const LogicBoard :: Players &player);


protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    const sf :: Vector2u m_windowSize;
    LogicBoard *m_logicBoard;
    EndGame *m_endGame;

    Sprite m_spriteBound;
    Sprite m_spriteBoard;
    sf :: Text m_refreshText;
    sf :: Font m_font;

    float m_widthOfCell;
    float m_heightOfCell;
    sf :: Vector2f m_startCell;

    Figure *m_selectedFigure;

    using Figures = std :: vector<std :: shared_ptr<Figure>>;
    std :: vector<Figures> m_figures;
    std :: unique_ptr<FigureFactory> m_factory;

    void createFigures(const LogicBoard :: Players &player, const Colors &color, const int &count);
    Figure* findFigure(const sf :: Vector2i &indexes);
    void unselectFig();
    bool moveFigure(const sf :: Vector2i &newIndexes);

    std :: vector<sf :: CircleShape> m_possibleMovesPoints;
    void createPossibleMovePoint(const int &x, const int &y);
    void calculatePossibleMoves();
};

#endif // UIBOARD_H
