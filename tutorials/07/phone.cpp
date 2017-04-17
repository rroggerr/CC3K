#include <iostream>
using namespace std;

struct Computer{
  void makeCall(){ cout << "Making call through the power of the internet\n";}
  void test(){cout << "Dialing out\n";}
};
struct Smartphone : public Computer {
  void makeCall(){ cout << "Attempting to make a call through Rogers\n";}
};
void testCall(Computer& c){
  c.test();
  c.makeCall();
}
int main(){
  Smartphone Nexus4;
  testCall(Nexus4);
  Computer * laptop = new Smartphone;
  laptop->makeCall();
  Nexus4.makeCall();
  Nexus4.test();
}
