//
//  gold.cc
//  CC3K
//
//

#include "gold.h"

Gold::Gold(char c) : Item('G'){
    if (c == '6') {
        amount = 1;
        available = true;
    } else if (c == '7') {
        amount = 2;
        available=true;
    } else if (c == '8') {
        amount = 4;
        available = true;
    } else if (c == '9') {
        amount = 6;
        available = false;
    }
    //dragonptr = NULL;
}

bool Gold::isAvailable(){
    return available;
}

int Gold::getGold() {
    return amount;
}

void Gold::setAvailable() {
    available = true;
}

Gold::~Gold(){
    //delete dragonptr;
}
/*
Enemy *Gold::getDragon(){
    return dragonptr;
}

void Gold::setDragon(Enemy *dragon){
    dragonptr = dragon;
}*/