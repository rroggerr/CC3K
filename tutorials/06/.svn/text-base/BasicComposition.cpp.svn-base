#include <string>
using namespace std;

class Dog{
  string breed;
 public:
  Dog(string breed) : breed(breed){}
};

class Sheriff{
  Dog rufus;
  string county;
 public:
  Sheriff(string county) : county(county){}
  void setDog(Dog d){ rufus = d;}
};

int main(){
  Dog d ("Corgi");
  Sheriff rosco("Hazard");
  rosco.setDog(d);
}
