//
//  gold.h
//  CC3K
//
//

#ifndef __gold_h__
#define __gold_h__

#include <iostream>
#include "item.h"
//#include "enemy.h"

class Gold : public Item {
    bool available;
    //Enemy *dragonptr;
public:
    Gold(char c);
    int getGold();
    bool isAvailable(); //for dragon gold
    void setAvailable();
    /*void setDragon(Enemy *dragon);
    Enemy* getDragon();*/
    ~Gold();
};

#endif
