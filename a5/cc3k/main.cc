//
//  main.cpp
//  CC3K
//
//

#include <iostream>
#include "dungeon.h"
#include <curses.h>
using namespace std;
void runGame();                             //declaration before use

int main(int argc, const char * argv[]){
    runGame();                              //might need to pass in args, filenames etc...
}


void runGame() {
    bool win = false;
    string strbuff;
    char race;
    cout<<"What race do you want to start with? ";
    cin>>race;                               //gets the race
    if (race != 'h'&&race != 'o'&&race != 'e'&&race != 'd') {
        race='h';                            //by default human
    }
    Dungeon *d = new Dungeon(race);
    d->readMap("default.dat");               //initializes Dungeon
    d->print();
    while (!win&&(strbuff!="q")&&!cin.eof()) {
        cin>>strbuff;                       //gets input
        if (strbuff == "r") {
            d->deleteDungeon();
            runGame();
        }
        if  (strbuff == "no" || strbuff == "so"||strbuff == "ea"||
             strbuff == "we"||strbuff == "ne"||strbuff == "nw"||
             strbuff == "se"||strbuff == "sw") {                             //case move
            win = d->movePlayer(strbuff);
        }
        else if (strbuff == "a"){
            cin>>strbuff;
            win = d->attack(strbuff);               //be sure to include the a in front of all the directions
        }
        else if (strbuff == "u"){
            cin>>strbuff;
            win = d->use(strbuff);
        }
                                //redraws board after every command
        if (!win) {
            win = d->step();
            d->print();
        }
    }
    d->deleteDungeon();
}
