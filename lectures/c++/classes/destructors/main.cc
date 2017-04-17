#include <iostream>
#include "node.h"
using namespace std;

int main () {
   Node *n = new Node(1, new Node(2, new Node(3, NULL)));

   cout << *n << endl;

   delete n;
}

