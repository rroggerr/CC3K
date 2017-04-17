//
//  tile.cc
//  CC3K
//
//

#include "tile.h"

Tile::Tile(char type):type(type){} //leave it like this

Tile::Tile():type(' '){};           //default constructor

char Tile::getChar(){
    return type;
}

Tile::~Tile(){}
