#include <exception>
#include <iostream>
using namespace std;
struct myexcept : public exception{
  const char* what() { return "myexcept";}
};
void rtn(){
   throw myexcept();
}

int main(){
  try{
     rtn();
  } catch (exception e){
     cout << "caught: " << e.what() << endl;
  } catch (myexcept e){
     cout << "caught: " << e.what() << endl;

  }
}
