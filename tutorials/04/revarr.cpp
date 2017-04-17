#include <iostream>
using namespace std;

#ifdef STACK
int * reverseCopy(int arr[]){
  int revArr[10];
  for(int i=0; i < 10; ++i){
    revArr[i] = arr[9-i];
  }
  return revArr;
}
#else
int * reverseCopy(int arr[]){
  int* revArr = new int[10];
  for(int i=0; i < 10; ++i){
    revArr[i] = arr[9-i];
  }
  return revArr;
}

#endif

int main(){
  int arr [] = {1,2,3,4,5,6,7,8,9,0};
  int *rarr = reverseCopy(arr);
  for(int i=0; i < 10; ++i){
    cout << rarr[i] << endl;
  }

}
