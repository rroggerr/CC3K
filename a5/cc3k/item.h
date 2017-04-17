//
//  item.h
//  CC3K
//
//

#ifndef __item_h__
#define __item_h__

#include <iostream>
#include "cell.h"

class Item : public Cell {
protected:
    int amount;       //amount of gold or amount of stats potion will change
public:
    Item();
    Item(char icon);
    int getAmount();  //returns the value as well
    virtual ~Item()=0;  //Item is also an abstract class
};


#endif
