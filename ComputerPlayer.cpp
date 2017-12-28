
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

ComputerPlayer::ComputerPlayer(int iTimeLimit, int iDepthLimit)
{
    LOG("%s IN\n", __FUNCTION__);
    m_iTimeLimitInSeconds = iTimeLimit;
    m_iDepthLimit = iDepthLimit;
    LOG("%s OUT\n", __FUNCTION__);
}

ComputerPlayer::~ComputerPlayer()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

void ComputerPlayer::SetTimeLimit(int iTimeLimit)
{
    m_iTimeLimitInSeconds = iTimeLimit;
}

int ComputerPlayer::GetTimeLimit()
{
    return m_iTimeLimitInSeconds;
}

void ComputerPlayer::SetDepthLimit(int iDepthLimit)
{
    m_iDepthLimit = iDepthLimit;
}

int ComputerPlayer::GetDepthLimit()
{
    return m_iDepthLimit;
}

void ComputerPlayer::PlayMove(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);
    BBoard.ReflectMove(Think(BBoard, eCurrentPlayer), eCurrentPlayer);
    LOG("%s OUT\n", __FUNCTION__);
}

Move ComputerPlayer::Think(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);
    // TODO : Understand the LIMIT and provide appropriate value
    IterativeDeepening::SetValues(LIMIT, (GetTimeLimit()*1000 - 200), GetDepthLimit()); // Convert to milliseconds and then provide some buffer
    Move m = IterativeDeepening::Search(BBoard, eCurrentPlayer);
    /*
    int iColumns = BBoard.GetNumberOfColumns();
    for (int j = 0; j < iColumns; j++)
    {
        if (BBoard.GetPositionValue(0, j) == NONE)
        {
            m.SetValues(j);
            break;
        }
    }
    */
    LOG("%s OUT\n", __FUNCTION__);
    return m;
}
