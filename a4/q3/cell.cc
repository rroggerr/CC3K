//
//  cell.cc
//  A4Q3
//
//  Cell controls each individual cell in the grid
//

#include "cell.h"
using namespace std;

Cell::Cell(){
    isAlive=false;
    numNeighbours=0;
    r=0;
    c=0;
}

void Cell::setLiving(){
    isAlive=true;
}

void Cell::setCoords(int r, int c, int width, int height, Xwindow *xw){   //new setCoords
    this->r = r;
    this->c = c;
    this->width=width;
    this->height=height;
    x = c * width;
    y = r * height;
    this->xw = xw;
}

void Cell::addNeighbour(Cell *neighbour){
    numNeighbours++;
    neighbours[numNeighbours-1]=neighbour;
}

void Cell::notify(){
    aliveNeighbours++;
}

void Cell::notifyNeighbours(){
    if (isAlive){
        for (int i = 0; i<numNeighbours; i++) {
            if (neighbours[i] != NULL){
            neighbours[i]->notify();              //NOTE: might have to change it
            }
        }
    }
}

void Cell::recalculate(){
    if ((aliveNeighbours < 2)||(aliveNeighbours > 3)) {
        isAlive = false;
    }
    else if (!isAlive&&(aliveNeighbours==3)){
        isAlive = true;
    }
    aliveNeighbours =0;
}

void Cell::notifyDisplay(TextDisplay &t){
    t.notify(r, c, isAlive);
    if (isAlive) {
        draw();
    }
    else {
        undraw();
    }
}

bool Cell::getState(){
    return isAlive;
}

void Cell::draw(){
    xw->fillRectangle(x, y, width, height);
}

void Cell::undraw() {
    xw->fillRectangle(x, y, width, height, Xwindow::White);
}

