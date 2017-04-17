//
//  potion.h
//  CC3K
//
//

#ifndef __potion_h__
#define __potion_h__

#include <iostream>
#include "item.h"

class Potion : public Item {
    char stat;      //the stats this potion is going to affect
    std::string type;
public:
    Potion();
    Potion(char type);
    char getStat();
    std::string getType();
    ~Potion();
};

#endif
