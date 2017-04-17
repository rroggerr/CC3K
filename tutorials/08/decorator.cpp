#include <string>
#include <iostream>
using namespace std;

class Taco {
  public:
    virtual double cost() = 0;
    virtual void desc() = 0;
    virtual ~Taco(){};
};
class PlainTaco : public Taco{
  public:
    double cost() { return 0.25;}
    void desc() { cout << "a corn flour tortilla";}
};
class Topping : public Taco{
  protected:
    Taco &t;
  public:
    Topping(Taco &t): t(t){}
};
class Lettuce : public Topping{
  public:
    Lettuce(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 0.50;}
    void desc() { t.desc(); cout << ", lettuce";}
};
class Beef : public Topping{
  public:
    Beef(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 0.50;}
    void desc() { t.desc(); cout << ", ground beef";}
};
class SourCream : public Topping{
  public:
    SourCream(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 0.50;}
    void desc() { t.desc(); cout << ", sour cream";}
};
class Cheese : public Topping{
  public:
    Cheese(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 0.75;}
    void desc() { t.desc(); cout << ", cheese";}
};
class Guac : public Topping{
  public:
    Guac(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 1.00;}
    void desc() { t.desc(); cout << ", guac";}
};
class GreekYogurt : public Topping{
  public:
    GreekYogurt(Taco& t) : Topping(t){}
    double cost() { return t.cost() + 0.75;}
    void desc() { t.desc(); cout << ", greek yogurt";}
};
int main(){
    PlainTaco t;
    Cheese t2 (t);
    Guac t3 (t2);
    Cheese t4 (t3);
    Beef t5 (t4);
    Cheese t6 (t5);
    SourCream dream (t6);

    // Note that reuse of a previous decorator
    Beef t7(t2);
    GreekYogurt t8 (t7);
    Guac healthy (t8);
    cout << "Cost of dream taco: " << dream.cost() << ", which includes: ";
    dream.desc(); cout << endl;
    cout << "Cost of healthy taco: " << healthy.cost()  << ", which includes: ";
    healthy.desc(); cout << endl;
}
