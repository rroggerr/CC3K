#include <string>
#include "book.h"

using namespace std;

Book::Book(string title, string author, int numPages):
  title(title), author(author), numPages(numPages) {}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
int Book::getNumPages() { return numPages; }
bool Book::isItHeavy() { return numPages > 200; }
