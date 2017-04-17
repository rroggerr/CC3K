//
//  cell.h
//  quadris
//
//  The Grid is made up of cells just like the
//       other assignment

#ifndef __cell_h__
#define __cell_h__

#include <iostream>

class Cell {
    int x, y;      //it's position on the grid
    char color;    //choose from ['i','j','l','o','s','z','t']  and 'd' for dead if its dead maybe
    bool alive;    //if it's dead then it has no color
    int genlevel;  //the level which the cell was generated in -1 denotes none
public:
    Cell();        //set to be dead by default
    ~Cell();
    void notifydisplay();
    void kill();
    void setColor(char color);
    void setCoords(int x, int y);
    
};

#endif
