#include "vector.h"

Vector::Vector(int x, int y, int z): x(x), y(y), z(z) {}
Vector::Vector(const Vector &v): x(v.x), y(v.y), z(v.z) {}

int Vector::getX() const {return x;}
int Vector::getY() const {return y;}
int Vector::getZ() const {return z;}

void Vector::setX(const int newX) {x = newX;}
void Vector::setY(const int newY) {y = newY;}
void Vector::setZ(const int newZ) {z = newZ;}

