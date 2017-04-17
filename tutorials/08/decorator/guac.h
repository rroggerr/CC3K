#ifndef __GUAC_H__
#define __GUAC_H__
#include "topping.h"


class Guac : public Topping{
  public:
    Guac(Taco& t);
    double cost(); 
    void desc();
};
#endif
