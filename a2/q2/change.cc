#include <iostream>
using namespace std;

int main()
{
    int types;
    cin >> types;
    int arr[types];
    int copy[types];
    int result[types];
    int amount;
    //init array
    for (int i = 0; i<= types-1; i++){
        cin >> arr[i];
    }
        cout << "done" << endl; //donemarker
    cin >> amount;
//cout << "Impossible" << endl;

    for (int i = 0; i<= types-1; i++){  //copy arr[] to copy[]
        copy[i]=arr[i];
    }
    for (int i = 0; i<= types-1; i++){  //init result[]
        result[i]=0;
    }
  int max = arr[0];
  int min = arr[0];
  for (int i=0;i<= types-1; i++){
      if(arr[i]>max){
          max = arr[i];
          }
    if(arr[i]<min){
        min = arr[i];
    }
  }
  // max and min determined
  for (int j=0; j<= types-1; j++){
      for(int i=0; j<=types-1; i++){
          if(arr[j]=max){
              int temp = amount%max;
              result[j]= temp;
              amount-=(max*temp);
              arr[j]=0;
          }
      }
    for (int i=0;i<= types-1; i++){
      if(arr[i]>max){
          max = arr[i];
          }
  }
      }

  if(amount != 0){
      cout << "Impossible";
  }
  else {
      for(int i; i<=types-1; i++){
          if(result[i]!=0){
              cout<<result[i]<<" x "<<copy[i]<<endl;
          }
      }
  }
   return 0;
}
