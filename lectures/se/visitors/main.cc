#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "csbook.h"
#include "comicbook.h"
#include "catalogue.h"
#include "BookVisitor.h"

using namespace std;

int main() {
  vector<Book*> collection;

  collection.push_back(new Book("War and Peace", "Tolstoy", 5000));
  collection.push_back(new Book("Peter Rabbit", "Potter", 50));
  collection.push_back(new CSBook("Programming for Beginners", "??", 200, "BASIC"));
  collection.push_back(new CSBook("Programming for Big Kids", "??", 200, "C++"));
  collection.push_back(new CSBook("Annotated Reference Manual", "??", 200, "C++"));
  collection.push_back(new ComicBook("Aquaman Swims Again", "??", 20, "Aquaman"));
  collection.push_back(new ComicBook("Clark Kent Loses His Glasses", "??", 20, "Superman"));
  collection.push_back(new ComicBook("Superman Saves the Day", "??", 20, "Superman"));

  vector<Book*>::iterator i;

  CatalogueVisitor v;

  for (i = collection.begin(); i != collection.end(); ++i)
    (*i)->accept(v);

  map<string, int> m = v.getResult();

  for (map<string, int>::iterator j = m.begin(); j != m.end(); ++j)
   cout << j->first << " " << j->second << endl;

  for (i = collection.begin(); i != collection.end(); ++i) delete (*i);
}
