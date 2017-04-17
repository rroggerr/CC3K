//
//  player.h
//  CC3K
//
//

#ifndef __player_h__
#define __player_h__

#include <iostream>
#include "character.h"

class Player : public Character {
    int gold;
    int aBuff;     //these two are set back to 0 after entering a new floor
    int dBuff;
    char race;
    bool potions[6] = {false};
public:
    Player(char race);
    void addGold(int gold);
    void usePotion(char c, int i);
    char getRace();
    int getGold();
    int getCurrentHP();
    int getAtk();            //implelemt these shit later
    int getDef();
    void clearPotion();      //call this when you get to a new floor
    void seenPotion(std::string potionstat);
    bool isSeenPotion(std::string potionstat);
};



#endif
