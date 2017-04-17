#include <iostream>
using namespace std;

int main() {
  int y = 5;
  int &r = y;

  cout << "y = " << y << "  r = " << r << endl;

  r = 10;

  cout << "y = " << y << "  r = " << r << endl;
}
