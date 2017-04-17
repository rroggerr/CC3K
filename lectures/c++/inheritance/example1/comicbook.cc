#include "comicbook.h"
#include <string>

using namespace std;

ComicBook::ComicBook(string title, string author, int numPages, string hero):
  Book(title, author, numPages), hero(hero) {}

string ComicBook::getHero() { return hero; }

