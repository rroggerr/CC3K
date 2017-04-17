#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include "pizza.h"

class Decorator: public Pizza {
 protected:
  Pizza *component;
 public:
  Decorator(Pizza *component);
  virtual ~Decorator();
};

#endif
