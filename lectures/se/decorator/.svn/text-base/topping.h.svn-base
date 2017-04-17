#ifndef __TOPPING_H__
#define __TOPPING_H__
#include "pizza.h"
#include "decorator.h"
#include <string>

class Topping: public Decorator {
  std::string theTopping;
  const float thePrice;
 public:
  Topping(std::string topping, Pizza *component);
  float price();
  std::string description();
};

#endif
