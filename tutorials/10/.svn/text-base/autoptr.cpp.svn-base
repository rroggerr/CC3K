#include <memory>
#include <iostream>
using namespace std;
int main(){
  auto_ptr<int> ap(new int);
  *ap = 7;
  cout << *ap << endl;
  // get() returns the pointer being stored
  cout << ap.get() << endl;
  auto_ptr<int> ap2 = ap;
  cout << ap.get() << endl;
  cout << ap2.get() << endl;
}
