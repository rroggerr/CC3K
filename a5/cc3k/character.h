//
//  character.h
//  CC3K
//
//

#ifndef __character_h__
#define __character_h__

#include <iostream>
#include "cell.h"

class Character : public Cell {
    
protected:
    int hp, atk, def, maxhp;
    bool alive;
    
public:
    Character();
    Character(char icon);
    virtual ~Character();
    int getHP();
    void setHP(int dhp);
    bool isDead();
};

#endif

