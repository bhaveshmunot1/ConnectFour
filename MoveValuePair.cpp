
#include "MoveValuePair.h"


MoveValuePair::MoveValuePair()
{
}


MoveValuePair::~MoveValuePair()
{
}

Move MoveValuePair::GetMove() 
{ 
    return m_MMove; 
}

void MoveValuePair::SetMove(Move MMove) 
{ 
    m_MMove = MMove; 
}

int MoveValuePair::GetValue() 
{ 
    return m_iEvaluationValue; 
}

void MoveValuePair::SetValue(int iValue) 
{ 
    m_iEvaluationValue = iValue; 
}
