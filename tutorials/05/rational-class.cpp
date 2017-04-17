#include <iostream>
using namespace std;

struct Rational{
    int numer, denom;
    double toDouble(){
        return (double)numer/denom;
    }
};

int main(){
  Rational r = {1,2}; // This is an object
  cout << r.toDouble() << endl;
}
