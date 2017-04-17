#include <iostream>
#include "vector.h"

using namespace std;

int main () {
  Vector v = {1,2};
  v = v + v;
  cout << v.x << " " << v.y << endl;
}

