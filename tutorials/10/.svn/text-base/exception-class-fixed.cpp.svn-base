#include <iostream>
#include <string>
using namespace std;
struct myexception{
  virtual string toString(){ return "myexception";}
  virtual ~myexception(){}
  
};
struct otherexception : public myexception{
  string contents;
  otherexception(string msg) : contents(msg){}
  string toString(){ return contents;}
  ~otherexception(){}
};
int main(){
  try{
    throw otherexception("Foobar");  
  } catch (myexception& e){
    cout << "Caught: " << e.toString() << endl;
  }
}
