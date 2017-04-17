struct Object{};
struct MyObject : public Object {
  int * arr;
  MyObject(): arr(new int[20]){}
  ~MyObject(){ delete [] arr;}
};
int main(){
  Object * o = new MyObject;
  // Use o
  // ..
  // Clean up
  delete o;
}
