//
//  tile.h
//  CC3K
//
//

#ifndef __tile_h__
#define __tile_h__

#include <iostream>
#include "cell.h"

class Tile {
    char type;
public:
    Tile(char type);
    Tile();
    ~Tile();
    char getChar();
};

#endif

