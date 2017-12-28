
#include "Board.h"


Board::Board()
{
    LOG("%s IN\n", __FUNCTION__);
    m_eWinner = NONE;
    m_iRows = ROW;
    m_iColumns = COLUMN;

    for (int i = 0; i < m_iRows; i++)
    {
        for (int j = 0; j < m_iColumns; j++)
        {
            m_BGrid[i][j] = NONE;
        }
    }
    LOG("%s OUT\n", __FUNCTION__);
}


Board::~Board()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

int Board::GetNumberOfRows()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
    return m_iRows;
}

int Board::GetNumberOfColumns()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
    return m_iColumns;
}

int Board::Evaluate(ePlayer eCurrentPlayer)
{
    LOG("%s IN\n", __FUNCTION__);    
    int iReturnEvaluation = 0;
    //TODO : Evaluation Function
    LOG("%s OUT\n", __FUNCTION__);
    return iReturnEvaluation;
}

bool Board::IsValid(Move MMove)
{
    bool bIsValidMove = false;
    if (m_BGrid[0][MMove.GetColumnNumber()] == NONE)
    {
        bIsValidMove = true;
    }
    return bIsValidMove;
}

void Board::ReflectMove(Move MMove, ePlayer eCurrentPlayer)
{
    if (IsValid(MMove))
    {        
        int iColumnNumber = MMove.GetColumnNumber();
        DISPLAY("Player%d's move in column number %d\n", eCurrentPlayer, iColumnNumber);
        int iCurrentRow = m_iRows - 1;
        while(iCurrentRow >= 0 && m_BGrid[iCurrentRow][iColumnNumber] != NONE)
        {
            iCurrentRow--;
        }
        m_BGrid[iCurrentRow][iColumnNumber] = eCurrentPlayer;
    }
}

void Board::RemoveMove(Move MMove)
{
    int iColumn = MMove.GetColumnNumber();
    int iCurrentRow = 0;
    while (m_BGrid[iCurrentRow][iColumn] == NONE)
    {
        iCurrentRow++;
    }
    m_BGrid[iCurrentRow][iColumn] = NONE;
}

void Board::Draw()
{
    for (int i = 0; i < m_iRows; i++)
    {
        for (int j = 0; j < m_iColumns; j++)
        {
            DISPLAY("%d ", m_BGrid[i][j]);
        }
        DISPLAY("\n");
    }
}

ePlayer Board::GetPositionValue(int iRowNumber, int iColumnNumber)
{
    return m_BGrid[iRowNumber][iColumnNumber];
}

void Board::SetPositionValue(int iRowNumber, int iColumnNumber, ePlayer ePlayerNumber)
{
    m_BGrid[iRowNumber][iColumnNumber] = ePlayerNumber;
}

bool Board::IsFull()
{
    bool bIsBoardFull = true;
    for (int i = 0; i < m_iColumns; i++)
    {
        if (m_BGrid[0][i] == NONE)
        {
            bIsBoardFull = false;
            break;
        }
    }
    return bIsBoardFull;
}

bool Board::WinningState()
{
    return CheckWinningState();
}

bool Board::CheckWinningState()
{
    bool bIsBoardInWinningState = false;

    for (int i = 0; i < m_iRows; i++)
    {
        for (int j = 0; j < m_iColumns; j++)
        {
            if (IsFourInARow(i, j))
            {
                bIsBoardInWinningState = true;
                goto ret;
            }
        }
    }
ret:
    return bIsBoardInWinningState;
}

bool Board::IsFourInARow(int tx, int ty)
{
    bool bIsFourInARow = false;
    int DeltaX[DIRECTIONS] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int DeltaY[DIRECTIONS] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int k = 0; k < DIRECTIONS; k++)
    {
        int cx = tx, cy = ty;
        ePlayer ma = m_BGrid[tx][ty];

        for (int step = 1; step < 4; step++)
        {
            cx += DeltaX[k]; cy += DeltaY[k];
            if (cx < 0 || cy < 0 || cx > (m_iRows-1) || cy > (m_iColumns-1) || m_BGrid[cx][cy] != ma)
                ma = NONE;
        }
        if (ma)
        {
            bIsFourInARow = true;
            m_eWinner = ma;
            break;
        }
    }
    return bIsFourInARow;
}

ePlayer Board::GetWinner()
{
    return m_eWinner;
}
