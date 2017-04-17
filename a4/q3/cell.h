#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"
#include "window.h"

/* The Neighbour Diagram
 ----------------
 |i-1 |    | i-1|
 |j-1 | i-1| j+1|
 ----------------
 | j-1| ij | j+1|
 |    |    |    |
 ----------------
 | j-1| i+1| i+1|
 | i+1|    | j+1|
 ----------------
 
 */
 const int maxNeighbours = 8;

class Cell {
    bool isAlive;
    int numNeighbours;
    Cell *neighbours[maxNeighbours];
    int r, c;
    int width, height, x, y;
    Xwindow *xw;
    // Add other private members if necessary
    int aliveNeighbours;             //added by me
    
    
    
public:
    Cell();  // Default constructor
    void setLiving();         // Explicitly sets me to living.
    void setCoords(int r, int c, int width, int height, Xwindow *xw);
    // void setCoords(int x, int y, int width, int height, Xwindow *w);
    void notifyDisplay(TextDisplay &t);
    
    void addNeighbour(Cell *neighbour);
    
    void notify();  // My neighbours will call this, to let me know
    // they're alive.
    
    void notifyNeighbours();   // Tell all of my neighbours that I am alive
    // (if I'm alive).
    
    void recalculate();       // Reassess my living-or-dead status, based on
    // info from neighbours.
    
    bool getState();           //returns true if im alive
    void draw();
    void undraw();
    
};

#endif

