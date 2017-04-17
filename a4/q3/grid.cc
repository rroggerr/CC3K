//
//  grid.cc
//  A2Q3
//
//  Controls the Grid which is a grid of Cells
//

#include "grid.h"
using namespace std;

Grid::Grid():gridSize(0),theGrid(NULL){
    xw = new Xwindow();
}

Grid::~Grid(){
    clearGrid();
    delete xw;
}

void Grid::clearGrid(){
    for (int i=0; i<gridSize; i++){
        delete [] theGrid[i];               // delete each row array
    }
    delete [] theGrid;                      // delete the array of rows
    delete td;
    gridSize=0;
}

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

void Grid::init(int n){
    if (theGrid!=NULL){
        clearGrid();                    // delete the array of rows
    }
    gridSize =n;
    theGrid= new Cell*[n];
    for (int i=0; i<n; i++){
        theGrid[i]=new Cell[n];
    }                                            //initialize 2D array
    
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            theGrid[i][j] = *new Cell();
            theGrid[i][j].setCoords(i, j, 500/n, 500/n, xw);      //set coordinates
            
        }
    }
    if (gridSize == 1) {
        //do nothing
    }
    else {
        for (int i=0; i<gridSize; i++) {
            for (int j =0; j<gridSize; j++) {        //nested for loop to initialize neighbours array
                if (i == 0 && j==0) {                                // LT corner
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                }
                else if (i == 0 && j==(gridSize-1)) {                // RT corner
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                }
                else if (i == (gridSize-1) && j==0) {                // LB corner
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                }
                else if (i == (gridSize-1) && j== (gridSize-1)) {    // RB corner
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                }
                else if (i == 0) {                                   // TOP
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
                }
                else if(i ==gridSize-1) {                            // BOTTOM
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                }
                else if (j == 0){                                    //LEFT
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
                }
                else if (j == gridSize-1){                           //RIGHT
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                }
                
                else {                                               //all 8 neighbours
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i-1][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i][j+1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j-1]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j]);
                    theGrid[i][j].addNeighbour(&theGrid[i+1][j+1]);
                }
            }
        }
    }
    
    td = new TextDisplay(n);
}

void Grid::turnOn(int r, int c){
    theGrid[r][c].setLiving();
    theGrid[r][c].notifyDisplay(*td);
}

void Grid::tick(){                                                 //notifies neighbour, recalculates and notifies display
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            theGrid[i][j].notifyNeighbours();
        }
    }
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            theGrid[i][j].recalculate();
            theGrid[i][j].notifyDisplay(*td);
        }
    }
}

ostream &operator<<(ostream &out, const Grid &g){
    out<<*g.td;                                                    //calls the Textdisplay operator<<
    return out;
}


