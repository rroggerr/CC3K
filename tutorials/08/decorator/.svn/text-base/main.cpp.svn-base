#include "plaintaco.h"
#include "cheese.h"
#include "beef.h"
#include "lettuce.h"
#include "sourcream.h"
#include "greekyogurt.h"
#include "guac.h"
#include <iostream>
using namespace std;

int main(){
    PlainTaco t;
    Cheese t2 (t);
    Guac t3 (t2);
    Cheese t4 (t3);
    Beef t5 (t4);
    Cheese t6 (t5);
    SourCream dream (t6);

    // Note that resuability of a previous decorator
    Beef t7(t2);
    GreekYogurt t8 (t7);
    Guac healthy (t8);
    cout << "Cost of dream taco: " << dream.cost() << ", which includes: ";  dream.desc(); cout << endl;
    cout << "Cost of healthy taco: " << healthy.cost()  << ", which includes: ";  healthy.desc(); cout << endl;
}
