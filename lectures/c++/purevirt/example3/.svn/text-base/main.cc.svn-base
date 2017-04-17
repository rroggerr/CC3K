#include <iostream>
#include <string>
#include "book.h"
#include "csbook.h"
#include "comicbook.h"

using namespace std;


int main() {
  CSBook csb1("Programming for Beginners", "Niklaus Wirth", 200, "BASIC");
  CSBook csb2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");

  AbstractBook *pb1 = &csb1;
  AbstractBook *pb2 = &csb2;
  
  *pb1 = *pb2;  // Prevented by compiler

  csb1 = csb2;

  cout << "Book 1: " << csb1.getTitle() << ", " << csb1.getAuthor() << ", "
       << csb1.getLanguage() << endl;

  cout << "Book 2: " << csb2.getTitle() << ", " << csb2.getAuthor() << ", "
       << csb2.getLanguage() << endl;
}
