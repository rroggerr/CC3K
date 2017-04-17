
#ifndef __board_h__
#define __board_h__

#include <iostream>
#include "block.h"
#include "textdisplay.h"
#include "cell.h"

class Board {
    Cell **theBoard;
    int level;
    int score;                 //these are THE ACTUAL SCORES
    int hiscore;
    Textdisplay *td;
    
public:
    Board(int level);
    ~Board();
    void notifydisplay(int i, int j);   //I think this will work
    void changelevel(int level);
};

#endif