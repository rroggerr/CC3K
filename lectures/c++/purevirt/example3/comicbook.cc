#include "comicbook.h"
#include <iostream>
#include <string>

using namespace std;

ComicBook::ComicBook(string title, string author, int numPages, string hero):
  AbstractBook(title, author, numPages), hero(hero) {}

ComicBook::ComicBook(const ComicBook &cb): AbstractBook(cb), hero(cb.hero) {}

ComicBook& ComicBook::operator=(const ComicBook &rhs) {
  cout << "ComicBook assignment operator running ..." << endl;
  if (this == &rhs) return *this;
  AbstractBook::operator=(rhs);
  hero = rhs.hero;
  return *this;
}

bool ComicBook::isItHeavy() { return getNumPages() > 30; }
string ComicBook::getHero() { return hero; }

// My favourite comic books are Superman comics.
bool ComicBook::favourite() { return hero == "Superman"; }
