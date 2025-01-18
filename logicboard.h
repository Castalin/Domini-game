#ifndef LOGICBOARD_H
#define LOGICBOARD_H
#include "figurefactory.h"
#include <vector>
#include "UI/boardconstants.h"

class LogicBoard
{

public:
    LogicBoard(BoardConstants &boardConst);
    ~LogicBoard();

    enum Players
    {
        PLAYER_1        = 0,
        PLAYER_2        = 1,
        MAX_PLAYERS     = 2
    };

    std::vector<std::vector<std::shared_ptr<Figure>>>* getfigures();

private:
    std :: vector<std :: vector<std :: shared_ptr<Figure>>> m_figures;

    const int m_rows;
    const int m_columns;
    const int m_rowsFig;
    const int m_columnsFig;
    const int m_countFigures;
    const int m_teams;

    std :: unique_ptr<FigureFactory> m_factory;
    std :: vector<std :: vector<char>> m_gameBoard;
    //Players m_moving;

    void createFigures(FigureFactory &factory, const Players &player, const Colors  &color);
    void reset();
};

#endif // LOGICBOARD_H
