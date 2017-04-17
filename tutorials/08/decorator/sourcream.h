#ifndef __SOURCREAM_H__
#define __SOURCREAM_H__
#include "topping.h"


class SourCream : public Topping{
  public:
    SourCream(Taco& t);
    double cost(); 
    void desc();
};
#endif
