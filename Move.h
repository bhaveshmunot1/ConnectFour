#pragma once

#include "CommonData.h"

class Move
{
    int m_iColumnNumber;    

public:
    Move();
    Move(int);
    ~Move();
    void SetValues(int);
    int GetColumnNumber();
};

