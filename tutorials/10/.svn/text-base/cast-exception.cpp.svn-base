#include <iostream>
#include <typeinfo> // gives bad_cast
using namespace std;

struct Base {
  virtual void speak(){cout << "Base" << endl;}
};
struct Derived : public Base{
  virtual void speak(){cout << "Derived" << endl;}
};


int main(){ 
  Base* bp = new Base;
  Derived* dp = dynamic_cast<Derived*>(bp);
  if(dp == 0) cerr << "dynamic_cast to pointer failed" << endl;
  try{
    Base& br = *new Base; 
    Derived& dr = dynamic_cast<Derived&>(br);
  }catch (bad_cast& e){
    cerr << "dynamic_cast to reference failed" << endl;
  }
}
