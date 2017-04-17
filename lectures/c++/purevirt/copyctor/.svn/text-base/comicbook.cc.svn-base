#include "comicbook.h"
#include <string>

using namespace std;

ComicBook::ComicBook(string title, string author, int numPages, string hero):
  Book(title, author, numPages), hero(hero) {}

bool ComicBook::isItHeavy() { return getNumPages() > 30; }
string ComicBook::getHero() { return hero; }

// My favourite comic books are Superman comics.
bool ComicBook::favourite() { return hero == "Superman"; }
