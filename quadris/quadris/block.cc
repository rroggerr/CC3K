//
//  block.cc
//  quadris
//
//  Created by Roger on 11/18/2013.
//
//

#include "block.h"
using namespace std;

Block::Block():alive(true), x(0),y(0){}    //TODO:CHANGE THE FUCKIN INITIAL X AND Y

Block::~Block(){}                          //TODO:DECIDE WAT THE FUCK TO DELETE LATER

void Block::notifydisplay(){               //TODO: DO SOME SHIT
    
}

void Block::notifyboard(){                 //TODO: DO SOME SHIT HERE AS WELL LATER
    
}

void Block::left(){
    if (x!=0) {
        x--;
    }
}

void Block::right(){}                     //MIGHT BE DIFFERENT FOR EACH BLOCK

void Block::down(){}                       //TODO: MIGHT B DIFFERENT FINISH THIS SHIT LATER

void Block::drop(){}                       //TODO: SAME SHIT DIFFERENT NAME

void Block::rotateCW(){};
void Block::rotateACW(){};
    