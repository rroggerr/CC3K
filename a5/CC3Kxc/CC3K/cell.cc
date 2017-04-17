//
//  cell.cc
//  CC3K
//
//

#include "cell.h"

Cell::Cell(){
    icon = ' ';
    x = -1;
    y = -1;
}

Cell::~Cell(){};

void Cell::setCoords(int x, int y){
    this->x = x;
    this->y = y;
}

char Cell::getIcon(){
    return icon;
}

Cell::Cell(char icon):icon(icon){}

int Cell::getX(){
    return x;
}

int Cell::getY(){
    return y;
}