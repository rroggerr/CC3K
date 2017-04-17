#include <iostream>
using namespace std;

class C {
 public:
  C() { cout << "Default constructor" << endl; }
  C(const C &other) { cout << "Copy constructor" << endl; }
  C &operator=(const C &other) { cout << "Assignment" << endl; return *this;}
};

C f() { cout << "f runs ..." << endl; return C(); }

int main() {
  C c = f();
  c = f();
}
