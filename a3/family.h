#ifndef __FAMILY_H__
#define __FAMILY_H__
#include <string>

const int maxChildren = 10;

struct FTree {
  std::string name;
  int numChildren;
  FTree *children[maxChildren];
};

#endif
