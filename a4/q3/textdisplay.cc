#include "textdisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(int n):gridSize(n){
    theDisplay = new char*[n];
    for (int i=0; i<n; i++) {
        theDisplay[i]= new char[n];
    }
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            theDisplay[i][j] = '_';
        }
    }
}

void TextDisplay::turnOffAll(){
    for (int i=0; i<gridSize; i++) {
        for (int j=0; j<gridSize; j++) {
            theDisplay[i][j] = '_';
        }
    }
}

void TextDisplay::notify(int r, int c, bool alive){
    if (alive) {
        theDisplay[r][c] = 'X';
    }
    else {
        theDisplay[r][c] = '_';
    }
}

TextDisplay::~TextDisplay(){
    for (int i=0; i<gridSize; i++){
        delete [] theDisplay[i]; // delete each row array
    }
    delete [] theDisplay;  // delete the array of rows
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    for (int i=0; i<td.gridSize; i++) {
        for (int j=0; j<td.gridSize; j++) {
            cout<<td.theDisplay[i][j];
        }
        cout<<endl;
    }
    return out;
}

