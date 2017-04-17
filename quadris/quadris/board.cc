
#include "board.h"

Board::Board(int level){
    td = new Textdisplay();
    theBoard = new Cell*[ROWS];
    for (int i=0; i<ROWS; i++) {
        theBoard[i] = new Cell[COLUMNS];
    }                                           //init blank 2D array
    
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            theBoard[i][j] = Cell();
            theBoard[i][j].setCoords(i, j);
            theBoard[i][j].kill();              //fill with dead Cells
        }
    }
    this->level = level;                        //constructor sets the level
}

Board::~Board(){
    delete td;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            delete theBoard[i][j];               //i dont know how to fucikin delete each Cell
        }
    }
    for (int i=0; i<ROWS; i++) {
        delete [] theBoard[i];
    }
    delete [] theBoard;
}

void changelevel(int level){
                                                //i think you might have to do something
}