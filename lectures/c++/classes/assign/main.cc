#include <iostream>
#include "node.h"
using namespace std;

int main () {
   Node n(1, new Node(2, new Node(3, NULL)));

   Node m(4, NULL);

   m = n;

   cout << n << endl;
   cout << m << endl;

   cout << endl;

   n.next->next->data = 7;

   cout << n << endl;
   cout << m << endl;

}

