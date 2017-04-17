//
//  cell.h
//  CC3K
//

#ifndef __cell_h__
#define __cell_h__

#include <iostream>

class Cell {
    
protected:
    char icon;
    int x, y;
public:
    Cell();
    Cell(char icon);
    virtual ~Cell();          
    void setCoords(int x, int y);
    char getIcon();
    int getX();
    int getY();
};

#endif

