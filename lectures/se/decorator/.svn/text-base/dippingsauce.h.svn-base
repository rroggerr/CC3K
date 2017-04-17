#ifndef __DIPPINGSAUCE_H__
#define __DIPPINGSAUCE_H__
#include "pizza.h"
#include "decorator.h"
#include <string>

class DippingSauce: public Decorator {
  std::string flavour;
 public:
  DippingSauce(std::string flavour, Pizza *component);
  float price();
  std::string description();
};

#endif
