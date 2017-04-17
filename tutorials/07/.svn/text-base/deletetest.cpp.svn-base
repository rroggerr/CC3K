#include <iostream>
using namespace std;

struct A{
  ~A(){
    cout << "~A" << endl;
  }
};

int main(){
  int j=1;
#ifdef ex1
  A *i = new A[10];
  for(int i=0; i < 10000; i++) j += i;
  delete [] i;
  for(int i=0; i < 10000; ++i) j += i;
#elif ex2
  A *i = new A[10];
  for(int i=0; i < 10000; i++) j += i;
  delete i;
  for(int i=0; i < 10000; ++i) j += i;
#elif ex3
  int *i = new int[10];
  for(int i=0; i < 10000; i++) j += i;
  delete i;
  for(int i=0; i < 10000; ++i) j += i;
#else
  int *i = new int[10];
  for(int i=0; i < 10000; i++) j += i;
  delete[] i;
  for(int i=0; i < 10000; ++i) j += i;
#endif
}
