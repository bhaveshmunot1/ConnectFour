#pragma once

#include <stdio.h>
#include <string.h>
#define __FUNCTION__ __PRETTY_FUNCTION__

/*Dimentions of board*/
#define ROW 7
#define COLUMN 8 
#define DIRECTIONS 8
#define LENGTH 20 // Length of name
#define INF 100000000
#define LIMIT 15000

enum ePlayer {
    NONE = 0,
    PLAYER1 = 1,
    PLAYER2 = 2,
    /*Add more values if there are any*/
};

#define DEBUG false
#define LOG if (DEBUG) printf
#define DISPLAY printf
#define INPUT scanf

int max(int a, int b);

int min(int a, int b);

ePlayer Opponent(ePlayer eCurrentPlayer);