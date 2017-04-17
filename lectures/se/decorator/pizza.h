#ifndef __PIZZA_H__
#define __PIZZA_H__
#include <string>

class Pizza {
 public:
  virtual float price() = 0;
  virtual std::string description() = 0;
  virtual ~Pizza();
};

#endif
