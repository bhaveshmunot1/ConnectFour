
#include "CommonData.h"
#include "Game.h"

int main()
{
    LOG("%s IN\n", __FUNCTION__);
    Game G;
    G.Toss();
    G.Play();
    G.End();
    LOG("%s OUT\n", __FUNCTION__);
    return 0;
}

