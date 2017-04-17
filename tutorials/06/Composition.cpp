#include <string>
using namespace std;

#ifdef SOL1
class Dog{
  string breed;
 public:
  Dog(string breed) : breed(breed){}
  Dog() : breed("Dane"){}
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
#elif SOL2
class Dog{
  string breed;
 public:
  Dog(string breed) : breed(breed){}
  string getBreed() { return breed;}
};

class Sheriff{
  Dog rufus;
  string county;
 public:
  Sheriff(string county, Dog d) : county(county), rufus(d.getBreed()){}
  void setDog(Dog d){ rufus = d;}
};

int main(){
  Dog d ("Corgi");
  Sheriff rosco("Hazard",d);
}
#else
class Dog{
  string breed;
 public:
  Dog(string breed) : breed(breed){}
  Dog() : breed("Dane"){}
};

class Sheriff{
  Dog rufus;
  string county;
 public:
  Sheriff(string county) : county(county), rufus("Hound"){}
  void setDog(Dog d){ rufus = d;}
};

int main(){
  Dog d ("Corgi");
  Sheriff rosco("Hazard");
  rosco.setDog(d);
}

#endif


