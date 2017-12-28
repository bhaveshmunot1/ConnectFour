#pragma once

#include "CommonData.h"
#include "Move.h"
#include "Board.h"

class Player
{
    char m_sName[LENGTH];
public:
    Player();
    ~Player();
    virtual void PlayMove(Board &, ePlayer) = 0; //Make the move on board
    virtual Move Think(Board &, ePlayer) = 0; //Think and Return a move to be played
};

