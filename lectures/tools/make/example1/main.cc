#include <iostream>
#include <string>
#include "book.h"
#include "csbook.h"
#include "comicbook.h"

using namespace std;

// Polymorphism in action.
void printMyFavourites(Book *myBooks[], int numBooks) {
  for (int i=0; i < numBooks; ++i) {
    if (myBooks[i]->favourite()) cout << myBooks[i]->getTitle() << endl;
  }
}

int main() {
  Book* collection[6];

  collection[0] = new Book("War and Peace", "Tolstoy", 5000);
  collection[1] = new Book("Peter Rabbit", "Potter", 50);
  collection[2] = new CSBook("Programming for Beginners", "??", 200, "BASIC");
  collection[3] = new CSBook("Programming for Big Kids", "??", 200, "C++");
  collection[4] = new ComicBook("Aquaman Swims Again", "??", 20, "Aquaman");
  collection[5] = new ComicBook("Clark Kent Loses His Glasses", "??", 20, "Superman");

  printMyFavourites(collection, 6);
  for (int i=0; i < 6; ++i) delete collection[i];
}
