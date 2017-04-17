#include <iostream>
using namespace std;

class A {
 public:
  int a;
  A():a(100) {}
  virtual ~A(){}
};

class B: virtual public A {
 public:
  int b;
  B():b(200) {}
  virtual ~B(){}
};

class C: virtual public A {
 public:
  int c;
  C():c(300) {}
  virtual ~C(){}
};

class D: public B, public C {
 public:
  int d;
  D():d(400) {}
  virtual ~D(){}
};

int main () {
  D d;
  unsigned int *p = reinterpret_cast<unsigned int *>(&d);

  cout << "Size of d: " << sizeof(d) << endl << endl;

  for (int i=0; i < sizeof(d)/sizeof(int); ++i) {
     cout << p[i] << endl;
  }

/*
  B b;

  p = reinterpret_cast<unsigned int *>(&b);

  cout << "Size of b: " << sizeof(b) << endl << endl;

  for (int i=0; i < sizeof(b)/sizeof(int); ++i) {
     cout << p[i] << endl;
  }
*/

  cout << endl;

  B::A *ap = &d;
  cout << &d << " " << reinterpret_cast<B::A*>(&d) << " ap = " << ap << endl;

  C::A *cap = &d;
  cout << &d << " " << reinterpret_cast<C::A*>(&d) << " cap = " << cap << endl;

  B *bp = &d;
  cout << &d << " " << reinterpret_cast<B*>(&d) << " bp = " << bp << endl;

  C *cp = &d;
  cout << &d << " " << reinterpret_cast<C*>(&d) << " cp = " << cp << endl;

}
