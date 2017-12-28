#pragma once
#include "Move.h"

class MoveValuePair
{
    Move m_MMove;
    int m_iEvaluationValue;
public:
    MoveValuePair();
    ~MoveValuePair();
    Move GetMove();
    void SetMove(Move MMove);
    int GetValue();
    void SetValue(int iValue);
};

