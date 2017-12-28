
#include "IterativeDeepening.h"

double diffclock(clock_t init_t){
    clock_t clock2 = clock();
    double diffticks = clock2 - init_t;
    double diffms = (diffticks) / (CLOCKS_PER_SEC / 1000);
    return diffms;
}

int IterativeDeepening::m_iLimit;
int IterativeDeepening::m_iTimeLimit;
int IterativeDeepening::m_iDepthLimit;

IterativeDeepening::IterativeDeepening()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}


IterativeDeepening::~IterativeDeepening()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

void IterativeDeepening::SetValues(int iLimit, int iTimeLimit, int iDepthLimit)
{
    m_iLimit = iLimit;
    m_iTimeLimit = iTimeLimit;
    m_iDepthLimit = iDepthLimit;
}

Move IterativeDeepening::Search(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);
    int OrderOfColumns[COLUMN] = { 3, 4, 2, 5, 6, 1, 0, 7 };
    clock_t init_t = clock();
    int Depth = 1;
    AlphaBetaPruning::SetValues(-INF / 20, +INF / 20);
    //call function to return column and evaluation value
    MoveValuePair MVPMvp = AlphaBetaPruning::AlphaBetaSearch(BBoard, Depth, eCurrentPlayer);
    Move m = MVPMvp.GetMove();
    while (diffclock(init_t) < m_iTimeLimit && Depth < m_iDepthLimit)
    {
        DISPLAY("%s Depth: %d, Value: %d\n", __FUNCTION__, Depth, abs(MVPMvp.GetValue()));
        if (abs(MVPMvp.GetValue()) > m_iLimit)
        {
            return m;
        }
        Depth++;
        MVPMvp = AlphaBetaPruning::AlphaBetaSearch(BBoard, Depth, eCurrentPlayer);
        m = MVPMvp.GetMove();
    }
    LOG("%s OUT\n", __FUNCTION__);
    return m;
}
