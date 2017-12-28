
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}


HumanPlayer::~HumanPlayer()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

void HumanPlayer::PlayMove(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);
    BBoard.ReflectMove(Think(BBoard, eCurrentPlayer), eCurrentPlayer);
    LOG("%s OUT\n", __FUNCTION__);
}

Move HumanPlayer::Think(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);    
    Move m;
    int iColumnNumber;
    DISPLAY("Your move?\t");
    INPUT("%d", &iColumnNumber);
    m.SetValues(iColumnNumber);
    LOG("%s OUT\n", __FUNCTION__);
    return m;
}
