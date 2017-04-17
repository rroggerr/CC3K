#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"

const int maxNeighbours = 8;

class Cell {
  bool isAlive;
  int numNeighbours;
  Cell *neighbours[maxNeighbours];
  int r, c;

  // Add other private members if necessary

 public:
  Cell();  // Default constructor
  void setLiving();         // Explicitly sets me to living.
  void setCoords(int r, int c);
  // void setCoords(int x, int y, int width, int height, Xwindow *w);
  void notifyDisplay(TextDisplay &t);

  void addNeighbour(Cell *neighbour);

  void notify();  // My neighbours will call this, to let me know
                  // they're alive.

  void notifyNeighbours();   // Tell all of my neighbours that I am alive
                            // (if I'm alive).

  void recalculate();       // Reassess my living-or-dead status, based on
                            // info from neighbours.

};

#endif
