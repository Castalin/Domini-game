#include "casualboard.h"

CasualBoard::CasualBoard()
    :m_rows{8}, m_columns{8}, m_countCells{m_rows * m_columns},
    m_rowsFig{3}, m_columnsFig{3}, m_countFig{m_rowsFig * m_columnsFig}
{

}

CasualBoard::~CasualBoard()
{

}
