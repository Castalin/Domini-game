#ifndef CASUALBOARD_H
#define CASUALBOARD_H


class CasualBoard
{
public:
    CasualBoard();
    virtual ~CasualBoard();

    enum Players
    {
        PLAYER_1        = 0,
        PLAYER_2        = 1,
        MAX_PLAYERS     = 2
    };

protected:
    const int m_rows;
    const int m_columns;
    const int m_countCells;
    const int m_rowsFig;
    const int m_columnsFig;
    const int m_countFig;
};

#endif // CASUALBOARD_H
