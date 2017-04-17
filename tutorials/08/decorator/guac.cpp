#include "guac.h"
#include <iostream>
using namespace std;

Guac::Guac(Taco& t) : Topping(t){}
double Guac::cost() { return t.cost() + 1.00;}
void Guac::desc() { t.desc(); cout << ", guac";}
