#include <cstring>

struct iString{
  char* chars;
  int length, capacity;
  iString(): chars(NULL),length(0),capacity(0) {}
  iString(const iString& a){
    capacity=a.capacity;
    chars = new char[capacity];
    length=a.length;
    strcpy(chars, a.chars);
  }
};
int main(){
  iString a;
  iString b = a; 
}
