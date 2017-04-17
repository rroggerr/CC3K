//
//  cell.cc
//  quadris
//
//  Created by Roger on 11/19/2013.
//
//

#include <iostream>
#include "cell.h"
using namespace std;

Cell::Cell(){
    x = 0;
    y = 0;
    alive = false;
    color = 'd';
}

Cell::~Cell(){}   // nothing in here so far

void Cell::kill(){
    alive = false;
    color = 'd';
}

void Cell::setColor(char color){
    this->color = color;
}

void Cell::setCoords(int x, int y){
    this->x = x;
    this->y = y;
}