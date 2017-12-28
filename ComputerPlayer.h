#pragma once
#include "Player.h"
#include "IterativeDeepening.h"

class ComputerPlayer :
    public Player
{
    int m_iTimeLimitInSeconds;
    int m_iDepthLimit;
public:
    ComputerPlayer();
    ComputerPlayer(int, int);
    ~ComputerPlayer();
    void PlayMove(Board &, ePlayer); //Make the move on board
    Move Think(Board &, ePlayer); //Think and Return a move to be played
    void SetTimeLimit(int);
    int GetTimeLimit();
    void SetDepthLimit(int);
    int GetDepthLimit();
};

