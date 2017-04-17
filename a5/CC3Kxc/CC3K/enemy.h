//
//  enemy.h
//  CC3K
//
//

#ifndef __enemy_h__
#define __enemy_h__

#include <iostream>
#include "character.h"
#include "gold.h"
#include <tgmath.h>

class Enemy : public Character {
    static bool hostile;
    bool moved;
    Gold *mygold;
public:
    Enemy(char c);
    bool isMoved();
    void setMoved(bool moved);
    void setHostile();
    bool isHostile();
    int getDef();
    int getAtk();
    int attackMe(int pcdef);
    void setGoldAvailable();
    void setGold(Gold *gp);
    Gold *getGold();
    ~Enemy();
};


#endif
