#pragma once
#include "CommonData.h"
#include "MoveValuePair.h"
#include "Board.h"
#include <vector>
using namespace std;

class AlphaBetaPruning
{
    static int m_iAlpha;
    static int m_iBeta;
    static int AlphaBetaMin(Board &, int, ePlayer);
    static int AlphaBetaMax(Board &, int, ePlayer);
    static int FillValidMoves(Move *, Board &);
public:
    AlphaBetaPruning();
    ~AlphaBetaPruning();
    static void SetValues(int, int);
    static MoveValuePair AlphaBetaSearch(Board &, int, ePlayer);
};

