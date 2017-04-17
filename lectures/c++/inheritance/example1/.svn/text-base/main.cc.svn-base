#include <iostream>
#include <string>
#include "book.h"
#include "csbook.h"
#include "comicbook.h"

using namespace std;

int main() {
  Book b("War and Peace", "Tolstoy", 5000);
  CSBook csb("Algorithms", "CLRS", 400, "C");
  ComicBook cb("Robin Kills Batman", "Robin", 20, "Robin");

  cout << "First book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "Second book: " << csb.getTitle() << "; " << csb.getAuthor()
       << "; " << (csb.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "Third book: " << cb.getTitle() << "; " << cb.getAuthor()
       << "; " << (cb.isItHeavy() ? "heavy" : "not heavy") << endl;
}
