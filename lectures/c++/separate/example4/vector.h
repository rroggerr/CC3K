#ifndef __VECTOR_H__
#define __VECTOR_H__

struct Vector {
  int x;
  int y;
};

Vector operator+(const Vector &v1, const Vector &v2);

extern int globalNum;

#endif
