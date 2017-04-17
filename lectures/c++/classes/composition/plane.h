#ifndef __PLANE_H__
#define __PLANE_H__
#include "vector.h"

class Plane {
  Vector v1, v2;
 public:
  Plane();
  Plane(const Plane &p);
};

#endif
