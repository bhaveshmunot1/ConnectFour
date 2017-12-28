#pragma once
#include "Player.h"
class HumanPlayer :
    public Player
{
public:
    HumanPlayer();
    ~HumanPlayer();
    void PlayMove(Board &, ePlayer); //Make the move on board
    Move Think(Board &, ePlayer); //Think and Return a move to be played
};

