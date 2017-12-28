#pragma once
#include "CommonData.h"
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Game
{
    Board m_BBoard;    
    HumanPlayer m_HHuman;
    ComputerPlayer m_CComp;
    Player *m_pPPlayer;
    ePlayer m_eCurrentPlayer;
    ePlayer m_eFirstPlayer;
    int m_iTotalMovesPlayed;
    
public:
    Game();
    ~Game();
    void Toss();
    void Play();
    void Pause();
    bool IsOver();
    void DeclareWinner();
    void End();
    void Toggle();
};

