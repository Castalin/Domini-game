#ifndef BOARDCONSTANTS_H
#define BOARDCONSTANTS_H

struct BoardConstants
{
    const int rows;
    const int columns;
    const int rowsFig;
    const int columnsFig;

    BoardConstants()
        :rows{8}, columns{8}, rowsFig{3}, columnsFig{3}
    {}
};

#endif // BOARDCONSTANTS_H
