int* foo(){ 
  int x = 42;
  if (x == 42){
    int y = 84;
  } // y is invalidated
  return &x; // x be invalidated
}

int main(){
  int x = *foo();
}
