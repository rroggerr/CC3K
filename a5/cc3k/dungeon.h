//
//  dungeon.h
//  CC3K
//
//

#ifndef __dungeon_h__
#define __dungeon_h__

#include <iostream>
#include "cell.h"
#include "tile.h"
#include "enemy.h"
#include "player.h"
#include <string>

const int HEIGHT = 25;
const int WIDTH = 79;
const int MAXPOTION= 10;
const int MAXENEMY = 20;
const int MAXGOLD = 10;
const std::string MAP = "default.dat";
const unsigned int seed = 3;

class Dungeon {
    Tile **map;
    Cell ***pos;
    Player *pp;
    int floor;              //thought we might need this
    bool cusMap;
    void genHelper(Cell *cptr);
    int staircb;            //the chamber stair cannot be in
    std::string actstr;
    bool mhos;
    
public:
    Dungeon(char race);     //include the race of the PC when initializing
    ~Dungeon();
    void readMap(std::string fname);
    bool attack(std::string direction);
    bool use(std::string direction);
    void generate();
    void print();
    bool step();            //or tick or whatever u call it
    bool movePlayer(std::string direction);
    void deleteDungeon();   //Destructor calls this!!
    void nextLevel();       //Generates another level
};

#endif

