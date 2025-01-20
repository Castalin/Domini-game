#ifndef LOGICBOARD_H
#define LOGICBOARD_H
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "abstarct/casualboard.h"
#include <utility>
#include <string>

using sf :: Vector2i;
using std :: vector;
using Player = CasualBoard :: Players;

class LogicBoard : public CasualBoard
{

public:
    LogicBoard();
    ~LogicBoard();

    void reset();
    bool checkSelectable(const Vector2i &indexes);
    bool checkEmptyCell(const Vector2i &indexes);
    void moveFigure(const Vector2i &oldPos, const Vector2i &newPos);
    bool checkWinner();
    const std :: string& getMessage();

    const vector< vector<char> >* getgameBoard() const;
    Player getTurn() const;


private:
    vector< vector<char>> m_gameBoard;
    Players m_turn;
    bool m_madeMove;
    std :: string m_message;
};

#endif // LOGICBOARD_H
