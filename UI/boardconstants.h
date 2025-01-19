#ifndef BOARDCONSTANTS_H
#define BOARDCONSTANTS_H

struct BoardConstants
{
    const int rows;
    const int columns;
    const int countCells;
    const int rowsFig;
    const int columnsFig;
    const int countFig;

    BoardConstants()
        :rows{8}, columns{8}, countCells{rows * columns},
         rowsFig{3}, columnsFig{3}, countFig{rowsFig * columnsFig}
    {}
};

#endif // BOARDCONSTANTS_H
