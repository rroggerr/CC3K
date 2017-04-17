#include "vector.h"
#include "plane.h"

Plane::Plane(): v1(1,0,0), v2(0,1,0) {}
Plane::Plane(const Plane &p): v1(p.v1), v2(p.v2) {}

