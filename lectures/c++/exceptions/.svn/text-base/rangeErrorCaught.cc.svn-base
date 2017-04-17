#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main () {
  vector<int> v;
  v.push_back(2);
  v.push_back(4);
  v.push_back(6);

  try {
     cout << v.at(3) << endl;  // out of range
  }
  catch (out_of_range r) {
     cerr << "Bad range " << r.what() << endl;
  }

  cout << "Done" << endl;
}
