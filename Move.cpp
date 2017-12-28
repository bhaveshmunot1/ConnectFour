
#include "Move.h"

Move::Move()
{

}

Move::Move(int iColumnNumber)
{
    LOG("%s IN\n", __FUNCTION__);
    m_iColumnNumber = iColumnNumber;
    LOG("%s OUT\n", __FUNCTION__);
}


Move::~Move()
{
    LOG("%s IN\n", __FUNCTION__);
    LOG("%s OUT\n", __FUNCTION__);
}

void Move::SetValues(int iColumnNumber)
{
    LOG("%s IN\n", __FUNCTION__);
    m_iColumnNumber = iColumnNumber;
    LOG("%s OUT\n", __FUNCTION__);
}

int Move::GetColumnNumber()
{
    return m_iColumnNumber;
}
