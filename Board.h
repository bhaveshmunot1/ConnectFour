#pragma once

#include "CommonData.h"
#include "Move.h"

class Board
{
    int m_iRows;
    int m_iColumns;
    ePlayer m_BGrid[ROW][COLUMN];
    ePlayer m_eWinner;
    bool CheckWinningState();
    bool IsFourInARow(int, int);
    
public:
    Board();
    Board(int, int);
    ~Board();
    ePlayer GetWinner();
    int GetNumberOfRows();
    int GetNumberOfColumns();
    void ReflectMove(Move, ePlayer);
    void RemoveMove(Move);
    bool IsValid(Move);
    int Evaluate(ePlayer);
    void Draw();
    ePlayer GetPositionValue(int, int);
    void SetPositionValue(int, int, ePlayer);
    bool IsFull();
    bool WinningState();
};

