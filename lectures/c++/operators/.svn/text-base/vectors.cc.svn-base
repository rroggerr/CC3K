#include <iostream>
using namespace std;

struct Vector {
  int x;
  int y;
};

Vector operator+(const Vector &v1, const Vector &v2) {
  Vector v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  return v;
}

Vector operator*(const Vector &v1, const int k) {
  Vector v;
  v.x = k * v1.x;
  v.y = k * v1.y;
  return v;
}

Vector operator*(const int k, const Vector &v1) {
  return v1 * k;
}

int main () {
  Vector v1 = {1, 2};
  Vector v2 = {3, 4};
  Vector v3 = v1 + v2;
  Vector v4 = 2 * v1;
  Vector v5 = v2 * 3;

  cout << "v3.x = " << v3.x << "   v3.y = " << v3.y << endl;
  cout << "v4.x = " << v4.x << "   v4.y = " << v4.y << endl;
  cout << "v5.x = " << v5.x << "   v5.y = " << v5.y << endl;
}
