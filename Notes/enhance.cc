/*     Structure

       ---------------------
       |     Component     | <---------------component(ptr)---------
       ---------------------                                       |
       | +operation        |                                       |
       ---------------------                                       |
               /_\                                                 |
                |                                                  |
                |                                                  |
                |------------------------------|                   |
 ----------------------             ----------------------         |
 | Concrete component |             | Decorator           |        |
  ---------------------             ----------------------   <>----|
 | +operation()       |             | +operation()        |
 ----------------------             -----------------------
                                            /_\
                                             |
                                -------------------------------------
                                |                                    |
                    ____________________                      ____________________
                    |ConcreteDecoratorA|                     |ConcreteDecoratorB |
                    --------------------                     ---------------------
                    |+operator()       |                     | + operator()      |
                    --------------------                     ---------------------

How it works:
-Component : defines the interface (provides basic object operations)
-ConcreteComponent : implements the interface
-Decorator : inherits from component and has a ptr to a component
      ::a Dectorator "is a" component and "has a" component
       redirects component methods to the component ptr
-Concrete Decorator : inherits from decorator
                    : overrde and compoment methods you want to "decorate"


---------------------------Example Pizza-----------------
 
                ----------
                |Pizza   | < --------component---------
                ----------                            |
                    /_\                               |
                     |                                |
        ----------------------------------            |
        |                                 |           |
 ----------------                  -------------      |
 | CrustAndSauce |                 |Decorator   |<>----
 -----------------                 --------------
                                        /_\
                                         |
                                         |
            ---------------------------------------------------------
            |                         |                             |
        ---------------       ------------------          --------------------
        |StuffedCrust |       |Topping         |          |Dipping Sauce     |
        ---------------       ------------------          --------------------
 
 */

//Code

class Pizza {
public:
    virtual float price()=0;            //interface only
    virtual string desc()=0;
    virtual ~Pizza(){}
};

class Decorator : public Pizza{
protected:
    Pizza *component;
public:
    Decorator(Pizza *p):component(p){}
    virtual ~Decorator(){
        delete component;
    }
};

class StuffedCrust: Decorator{
public:
    StuffedCrust(Pizza *p):Decorator(p){}
    float price{
        return component->price() + 2.69;
    }
    string desc(){
        return component->desc() + "with stuffed crust";
    }
};