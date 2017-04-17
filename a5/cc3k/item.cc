//
//  item.cc
//  CC3K
//
//

#include "item.h"

int Item::getAmount() {
    return amount;
}

Item::Item(){}

Item::Item(char icon) : Cell(icon){
    
}

Item::~Item(){}
