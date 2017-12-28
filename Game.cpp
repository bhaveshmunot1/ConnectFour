
#include "Game.h"


Game::Game()
{
    LOG("%s IN\n", __FUNCTION__);
    m_pPPlayer = NULL;
    m_iTotalMovesPlayed = 0;
    m_CComp.SetTimeLimit(3);
    m_CComp.SetDepthLimit(41);
    LOG("%s OUT\n", __FUNCTION__);
}


Game::~Game()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

void Game::Toss()
{
    LOG("%s IN\n", __FUNCTION__);
    int toss;
    DISPLAY("Do you want a toss, or your choice only?\t");
    INPUT("%d", &toss);
    if (toss)
    {
        m_eFirstPlayer = PLAYER1;
    }
    else
    {
        ePlayer choice;
        INPUT("%d", &choice);
        m_eFirstPlayer = choice;
    }
    LOG("%s OUT\n", __FUNCTION__);
}

void Game::Play()
{
    LOG("%s IN\n", __FUNCTION__);
    m_eCurrentPlayer = m_eFirstPlayer;
    if (m_eCurrentPlayer == PLAYER1)
    {
        m_pPPlayer = &m_HHuman;
    }
    else
    {
        m_pPPlayer = &m_CComp;
    }

    while (!IsOver())
    {
        m_BBoard.Draw();
        m_pPPlayer->PlayMove(m_BBoard, m_eCurrentPlayer);
        Toggle();
    }

    LOG("%s OUT\n", __FUNCTION__);
}

void Game::Pause()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

bool Game::IsOver()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
    return m_BBoard.IsFull() || m_BBoard.WinningState();
}

void Game::DeclareWinner()
{
    LOG("%s IN\n", __FUNCTION__);
    DISPLAY(" The Winner is Player%d!", m_BBoard.GetWinner());
    LOG("%s OUT\n", __FUNCTION__);
}

void Game::End()
{
    LOG("%s IN\n", __FUNCTION__);
    if (IsOver())
    {
        DeclareWinner();
    }
    else
    {
        //TODO
    }
    LOG("%s OUT\n", __FUNCTION__);
}

void Game::Toggle()
{
    LOG("%s IN\n", __FUNCTION__);
    if (m_pPPlayer == &m_HHuman)
    {
        m_pPPlayer = &m_CComp;
        m_eCurrentPlayer = PLAYER2;
    }
    else
    {
        m_pPPlayer = &m_HHuman;
        m_eCurrentPlayer = PLAYER1;
    }
    LOG("%s OUT\n", __FUNCTION__);
}
