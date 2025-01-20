#ifndef LOGICBOARD_H
#define LOGICBOARD_H
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "abstarct/casualboard.h"
#include <utility>
#include <string>

class LogicBoard : public CasualBoard
{

public:
    LogicBoard();
    ~LogicBoard();

    void reset();
    bool checkSelectable(const sf :: Vector2i &indexes);
    bool checkEmptyCell(const sf :: Vector2i &indexes);
    void moveFigure(const sf :: Vector2i &oldPos, const sf :: Vector2i &newPos);
    bool checkWinner();
    const std :: string& getMessage();

private:
    std :: vector<std :: vector<char>> m_gameBoard;
    Players m_turn;
    bool m_madeMove;
    std :: string m_message;
};

#endif // LOGICBOARD_H
