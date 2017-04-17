

#include "textdisplay.h"
#include <iomanip>

using namespace std;

Textdisplay::Textdisplay(){
    theDisplay = new char*[ROWS];
    for (int i=0; i<ROWS; i++) {
        theDisplay[i] = new char[COLUMNS];
    }                                           //init blank 2D array
    
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            theDisplay[i][j] = '0';
        }
    }
}

Textdisplay::~Textdisplay(){
    for (int i=0; i<ROWS; i++) {
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
}

void Textdisplay::clear(){                      //clears the display to all '0'
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            theDisplay[i][j] = '0';
        }
    }
}

void Textdisplay::print(){                       //prints every fuckin thing, including scores n shit
    cout<<"Level:    "<<setw(4)<<level<<endl;
    cout<<"Score:    "<<setw(4)<<score<<endl;
    cout<<"Hi Score: "<<setw(4)<<hiscore<<endl;
    cout<<"----------"<<endl;
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            cout<<theDisplay[i][j];
        }
        cout<<endl;
    }
    cout<<"----------"<<endl;
}

void Textdisplay::updateme(){
    
}