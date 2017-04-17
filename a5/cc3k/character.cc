//
//  character.cc
//  CC3K
//
//

#include "character.h"

Character::Character(char icon):Cell(icon) {
    
}

int Character::getHP() {
    return hp;
}

void Character::setHP(int dhp){   //the difference not the new hp
    hp +=dhp;
    if (hp<0) {
        hp=0;
    }
}

bool Character::isDead() {
    if (hp==0){
        return true;
    }
    else {
        return false;
    }
}

Character::Character() {}

Character::~Character() {}
