
#ifndef __textdisplay_h__
#define __textdisplay_h__

#include <iostream>
const int ROWS = 15;
const int COLUMNS = 10;        //just dont change this

class Textdisplay {
    char **theDisplay;
    int level;
    int score;                 //these are for printing only, not for tracking
    int hiscore;
public:
    Textdisplay();
    ~Textdisplay();
    void print();
    void updateme();          //called by Board to update everything
    void clear();             //clears the display to all '0'
};

#endif
