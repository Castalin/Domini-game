#ifndef AI_H
#define AI_H

#include <vector>
#include "figure.h"
#include "abstarct/casualboard.h"
#include "abstarct/i_findoptimal.h"
#include "memory"

using board = std :: vector<std :: vector<char>>;
using playerType = CasualBoard :: Players;
using std :: vector;
using sf :: Vector2i;

class AI : public I_findOptimal
{
public:
    AI(const board *gameBoard, const vector<std :: shared_ptr<Figure>> *figures, playerType type = CasualBoard :: PLAYER_2);

    void findOptimal() override;

    playerType getplayerType() const;

    Vector2i getoptimalFig() const;
    Vector2i getoptimalCell() const;

private:
    vector<vector<float>> m_points;
    const vector< vector<char>> *m_gameBoard;
    const vector<std :: shared_ptr<Figure>> *m_figures;
    playerType m_playerType;

    vector<Vector2i> m_possibleMoves;
    Vector2i m_optimalFig;
    Vector2i m_optimalCell;

    const int m_rows;
    const int m_columns;

    void findPossibleMoves(const Figure &fig);
    void findOptimalCell(const Figure &fig, float &diff);

    inline float countDiff(const Vector2i &newPos, const Vector2i &pos);
};

#endif // AI_H
