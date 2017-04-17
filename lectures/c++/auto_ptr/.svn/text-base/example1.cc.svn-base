#include <iostream>
#include <memory>
using namespace std;

class Basic {
 public:
  int x;
  Basic (int x) : x(x) { cout << "Basic ctor running (x = " << x << ")" << endl; }
  ~Basic() { cout << "Basic dtor running" << endl; }
};

int main () {
  auto_ptr<Basic> bp(new Basic(5));

  cout << "Access x field through smart ptr:  " << bp->x << endl;
}
