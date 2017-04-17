#include "comicbook.h"
#include <iostream>
#include <string>

using namespace std;

ComicBook::ComicBook(string title, string author, int numPages, string hero):
  Book(title, author, numPages), hero(hero) {}

ComicBook::ComicBook(const ComicBook &cb): Book(cb), hero(cb.hero) {}

ComicBook& ComicBook::operator=(const ComicBook &rhs) {
  cout << "ComicBook assignment operator running ..." << endl;
  if (this == &rhs) return *this;
  Book::operator=(rhs);
  hero = rhs.hero;
  return *this;
}

bool ComicBook::isItHeavy() { return getNumPages() > 30; }
string ComicBook::getHero() { return hero; }

// My favourite comic books are Superman comics.
bool ComicBook::favourite() { return hero == "Superman"; }
