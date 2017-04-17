#include <iostream>
#include <string>
#include "book.h"
#include "csbook.h"
#include "comicbook.h"

using namespace std;

int main() {
  ComicBook cb("Robin Kills Batman Twice", "Robin", 40, "Robin");

  Book b = cb;

  cout << "The comic book: " << cb.getTitle() << "; " << cb.getAuthor()
       << "; " << (cb.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << endl << "Through pointers: " << endl;

  ComicBook *pcb = new ComicBook("Spiderman Unabridged", "Peter Parker", 100, "Spiderman");
  Book *pb = pcb;

  cout << "The comic book ptr: " << pcb->getTitle() << "; " << pcb->getAuthor()
       << "; " << (pcb->isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book ptr: " << pb->getTitle() << "; " << pb->getAuthor()
       << "; " << (pb->isItHeavy() ? "heavy" : "not heavy") << endl;

}
